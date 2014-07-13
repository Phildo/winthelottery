#include "model.h"
#include <android/log.h>

//absolutely covered with edge cases
ticket_i Model::purchaseTicket(ticket t, ticket_i run_length)
{
  if(run_length < 1) return 0;
  if(t+run_length-1 > MAX_TICKET) run_length = MAX_TICKET-t+1;
  ticket_run run(t, t+run_length-1); //the run to attempt purchase

  int l = ticket_runs.length();
  ticket_i bought = 0;

  int i = 0; //first ticket that starts after run starts
  while(i < l && ticket_runs[i].ticket_from < run.ticket_from) i++;

  if(i > 0 && ticket_runs[i-1].ticket_to >= run.ticket_from-1) //run will merge with previous
    i--;
  else //run is created new
  {
    ticket_run tmp(run.ticket_from,run.ticket_from);
    bought++;
    dollars--;
    ticket_runs.insert(i,tmp);
  }

  //at this point, ticket_runs[i] is a ticket with run length at least 1 (already payed for)
  //and must be extended for the full length of the run, potentially merging with further runs

  ticket_i bought_til = ticket_runs[i].ticket_to;
  while(bought_til < run.ticket_to)
  {
    ticket_i affordable_to = (dollars < run.ticket_to-bought_til) ? bought_til+dollars : run.ticket_to;
    if(i == ticket_runs.length()-1 || affordable_to < ticket_runs[i+1].ticket_from-1) //free to purchase rest of run
    {
      bought  += affordable_to-bought_til;
      dollars -= affordable_to-bought_til;
      ticket_runs[i].ticket_to = affordable_to;
      bought_til = ticket_runs[i].ticket_to;

      tickets_owned += bought;
      return bought;
    }
    else //purchase until conflict
    {
      bought  += ticket_runs[i+1].ticket_from-bought_til-1;
      dollars -= ticket_runs[i+1].ticket_from-bought_til-1;
      ticket_runs[i].ticket_to = ticket_runs[i+1].ticket_to;
      bought_til = ticket_runs[i].ticket_to;
      ticket_runs.remove(i+1);
    }
  }

  tickets_owned += bought;
  return bought;
}

ticket_i Model::purchaseRandom(ticket_i num)
{
  if(num > dollars) num = dollars;
  if(tickets_owned+num > MAX_TICKET) num = MAX_TICKET-tickets_owned;

  dollars -= num;
  num_random += num;
  tickets_owned += num;
  return num;
}

ticket Model::getTicket(ticket_i t)
{
}

void Model::print()
{
  __android_log_print(ANDROID_LOG_INFO, "WTL", "Dollars: %lld",dollars);
  __android_log_print(ANDROID_LOG_INFO, "WTL", "Owned: %lld",tickets_owned);
  this->printRuns();
}
void Model::printRuns()
{
  for(int i = 0; i < ticket_runs.length(); i++)
    __android_log_print(ANDROID_LOG_INFO, "WTL", "[%lld,%lld]",ticket_runs[i].ticket_from,ticket_runs[i].ticket_to);
}

int Model::test()
{
  //currently using this to actually test the model, not test whether we won
  __android_log_print(ANDROID_LOG_INFO, "WTL", "Test:");

  dollars = 100;
  ticket_i bought = 0;
  bool success = true;

  //first purchase
  bought = this->purchaseTicket(0, 10);
  success = (
    bought == 10 &&
    dollars == 90 &&
    tickets_owned == 10 &&
    ticket_runs.length() == 1 &&
    ticket_runs[0].ticket_from == 0 &&
    ticket_runs[0].ticket_to == 9
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded 1!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed 1!"); return 1; }

  //second purchase
  bought = this->purchaseTicket(20, 10);
  success = (
    bought == 10 &&
    dollars == 80 &&
    tickets_owned == 20 &&
    ticket_runs.length() == 2 &&
    ticket_runs[1].ticket_from == 20 &&
    ticket_runs[1].ticket_to == 29
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded 2!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed 2!"); return 1; }

  //front overlap
  bought = this->purchaseTicket(19, 5);
  success = (
    bought == 1 &&
    dollars == 79 &&
    tickets_owned == 21 &&
    ticket_runs.length() == 2 &&
    ticket_runs[1].ticket_from == 19 &&
    ticket_runs[1].ticket_to == 29
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded front overlap!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed front overlap!"); return 1; }

  //back overlap
  bought = this->purchaseTicket(25, 6);
  success = (
    bought == 1 &&
    dollars == 78 &&
    tickets_owned == 22 &&
    ticket_runs.length() == 2 &&
    ticket_runs[1].ticket_from == 19 &&
    ticket_runs[1].ticket_to == 30
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded back overlap!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed back overlap!"); return 1; }

  //full overlap (buy engulfs run)
  bought = this->purchaseTicket(18, 14);
  success = (
    bought == 2 &&
    dollars == 76 &&
    tickets_owned == 24 &&
    ticket_runs.length() == 2 &&
    ticket_runs[1].ticket_from == 18 &&
    ticket_runs[1].ticket_to == 31
  );
  this->print();
  if(success)__android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded full overlap (ber) !");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed full overlap (ber)!"); return 1; }

  //full overlap (run engulfs buy)
  bought = this->purchaseTicket(22, 2);
  success = (
    bought == 0 &&
    dollars == 76 &&
    tickets_owned == 24 &&
    ticket_runs.length() == 2 &&
    ticket_runs[1].ticket_from == 18 &&
    ticket_runs[1].ticket_to == 31
  );
  this->print();
  if(success)__android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded full overlap (reb) !");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed full overlap (reb)!"); return 1; }

  //purchase 1
  bought = this->purchaseTicket(40, 1);
  success = (
    bought == 1 &&
    dollars == 75 &&
    tickets_owned == 25 &&
    ticket_runs.length() == 3 &&
    ticket_runs[2].ticket_from == 40 &&
    ticket_runs[2].ticket_to == 40
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded Buy 1!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed Buy 1!"); return 1; }

  //buy begins at run of 1
  bought = this->purchaseTicket(40, 5);
  success = (
    bought == 4 &&
    dollars == 71 &&
    tickets_owned == 29 &&
    ticket_runs.length() == 3 &&
    ticket_runs[2].ticket_from == 40 &&
    ticket_runs[2].ticket_to == 44
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded front overlap 1!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed front overlap 1!"); return 1; }

  //purchase 1 (again)
  bought = this->purchaseTicket(50, 1);
  success = (
    bought == 1 &&
    dollars == 70 &&
    tickets_owned == 30 &&
    ticket_runs.length() == 4 &&
    ticket_runs[3].ticket_from == 50 &&
    ticket_runs[3].ticket_to == 50
  );
  this->print();
  if(success)__android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded Buy 1 (redux) !");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed Buy 1 (redux)!"); return 1; }

  //buy ends at run of 1
  bought = this->purchaseTicket(46, 5);
  success = (
    bought == 4 &&
    dollars == 66 &&
    tickets_owned == 34 &&
    ticket_runs.length() == 4 &&
    ticket_runs[3].ticket_from == 46 &&
    ticket_runs[3].ticket_to == 50
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded back overlap 1!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed back overlap 1!"); return 1; }

  //take over the whole thing
  bought = this->purchaseTicket(0, 60);
  success = (
    bought == 26 &&
    dollars == 40 &&
    tickets_owned == 60 &&
    ticket_runs.length() == 1 &&
    ticket_runs[0].ticket_from == 0 &&
    ticket_runs[0].ticket_to == 59
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded takeover!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed takeover!"); return 1; }

  //run out of money
  bought = this->purchaseTicket(70, 50);
  success = (
    bought == 40 &&
    dollars == 0 &&
    tickets_owned == 100 &&
    ticket_runs.length() == 2 &&
    ticket_runs[1].ticket_from == 70 &&
    ticket_runs[1].ticket_to == 109
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded run out of money!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed run out of money!"); return 1; }

  dollars = 100; //REPLENISH FUNDS FOR MORE TESTING

  //start next to run
  bought = this->purchaseTicket(60, 2);
  success = (
    bought == 2 &&
    dollars == 98 &&
    tickets_owned == 102 &&
    ticket_runs.length() == 2 &&
    ticket_runs[0].ticket_from == 0 &&
    ticket_runs[0].ticket_to == 61
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded start next!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed start next!"); return 1; }

  //finish next to run
  bought = this->purchaseTicket(68, 2);
  success = (
    bought == 2 &&
    dollars == 96 &&
    tickets_owned == 104 &&
    ticket_runs.length() == 2 &&
    ticket_runs[1].ticket_from == 68 &&
    ticket_runs[1].ticket_to == 109
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded finish next!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed finish next!"); return 1; }

  //fill gap exactly
  bought = this->purchaseTicket(62, 6);
  success = (
    bought == 6 &&
    dollars == 90 &&
    tickets_owned == 110 &&
    ticket_runs.length() == 1 &&
    ticket_runs[0].ticket_from == 0 &&
    ticket_runs[0].ticket_to == 109
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded fill gap!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed fill gap!"); return 1; }

  //final test- a combination of a ton of BS
    //first, just buy a bunch of runs to set up the scene (no need to verify validity- previous tests should suffice)
  this->purchaseTicket(120, 12);
  this->purchaseTicket(140, 5);
  this->purchaseTicket(150, 1);
  this->purchaseTicket(199, 1);
    //purchase will start in middle of a run, merge/engulf multiple runs of various lengths, and run out of money on the ticket before final run
  bought = this->purchaseTicket(10, 10000);
  success = (
    bought == 71 &&
    dollars == 0 &&
    tickets_owned == 200 &&
    ticket_runs.length() == 1 &&
    ticket_runs[0].ticket_from == 0 &&
    ticket_runs[0].ticket_to == 199
  );
  this->print();
  if(success) __android_log_print(ANDROID_LOG_INFO, "WTL", "Succeeded fill gap!");
  else { __android_log_print(ANDROID_LOG_INFO, "WTL", "Failed fill gap!"); return 1; }

  __android_log_print(ANDROID_LOG_INFO, "WTL", "Success");

}

