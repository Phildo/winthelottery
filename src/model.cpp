#include "model.h"
#include "logger.h"
#include <stdlib.h>
#include <time.h>

Model::Model() : dollars(0), tickets_owned(0), num_random(0), ticket_runs() { }
Model::~Model() { }

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

  ticket bought_til = ticket_runs[i].ticket_to;
  while(bought_til < run.ticket_to)
  {
    ticket affordable_to = (dollars < run.ticket_to-bought_til) ? bought_til+dollars : run.ticket_to;
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

ticket_i* Model::testWin(ticket w) //'w'inning ticket
{
  ticket f; //'f'rom ticket
  ticket t; //'t'o ticket

  ticket_human wh = this->humanReadableTicket(w);
  ticket_human fh;
  ticket_human th;
  ticket_combination owned;

  //used all the time, so just create them once
  ticket_combination winning_combination(wh);
  ball_run full_ball(MIN_BALL,MAX_BALL);
  ticket_combination fullc(full_ball, full_ball, full_ball, full_ball, full_ball, full_ball);

  winCounts[0] = 0;
  winCounts[1] = 0;
  winCounts[2] = 0;
  winCounts[3] = 0;
  winCounts[4] = 0;
  winCounts[5] = 0;

  for(int i = 0; i < ticket_runs.length(); i++)
  {
    f = ticket_runs[i].ticket_from; fh = this->humanReadableTicket(f);
    t = ticket_runs[i].ticket_to;   th = this->humanReadableTicket(t);
    while(f != t)
    {
      if(f % BALL_0_I == 0 && f + BALL_0_I <= t) //own full 0 run
      {
        owned = fullc;
        owned.ball_runs[5] = ball_run(fh.balls[5]);
        this->count6RangeIntersections(owned, winning_combination, full_ball);
        this->count5RangeIntersections(owned, winning_combination, full_ball);
        f += BALL_0_I;
      }
      if(f % BALL_1_I == 0 && f + BALL_1_I <= t) //own full 1 run
      {
        owned = fullc;
        owned.ball_runs[5] = ball_run(fh.balls[5]);
        owned.ball_runs[4] = ball_run(fh.balls[4]);
        this->count6RangeIntersections(owned, winning_combination, full_ball);
        this->count5RangeIntersections(owned, winning_combination, full_ball);
        f += BALL_1_I;
      }
      if(f % BALL_2_I == 0 && f + BALL_2_I <= t) //own full 2 run
      {
        owned = fullc;
        owned.ball_runs[5] = ball_run(fh.balls[5]);
        owned.ball_runs[4] = ball_run(fh.balls[4]);
        owned.ball_runs[3] = ball_run(fh.balls[3]);
        this->count6RangeIntersections(owned, winning_combination, full_ball);
        this->count5RangeIntersections(owned, winning_combination, full_ball);
        f += BALL_2_I;
      }
      if(f % BALL_3_I == 0 && f + BALL_3_I <= t) //own full 3 run
      {
        owned = fullc;
        owned.ball_runs[5] = ball_run(fh.balls[5]);
        owned.ball_runs[4] = ball_run(fh.balls[4]);
        owned.ball_runs[3] = ball_run(fh.balls[3]);
        owned.ball_runs[2] = ball_run(fh.balls[2]);
        this->count6RangeIntersections(owned, winning_combination, full_ball);
        this->count5RangeIntersections(owned, winning_combination, full_ball);
        f += BALL_3_I;
      }
      if(f % BALL_4_I == 0 && f + BALL_4_I <= t) //own full 4 run
      {
        owned = fullc;
        owned.ball_runs[5] = ball_run(fh.balls[5]);
        owned.ball_runs[4] = ball_run(fh.balls[4]);
        owned.ball_runs[3] = ball_run(fh.balls[3]);
        owned.ball_runs[2] = ball_run(fh.balls[2]);
        owned.ball_runs[1] = ball_run(fh.balls[1]);
        this->count6RangeIntersections(owned, winning_combination, full_ball);
        this->count5RangeIntersections(owned, winning_combination, full_ball);
        f += BALL_4_I;
      }
      if(f % BALL_5_I == 0 && f + BALL_5_I <= t) //own full 5 run (lol, 1 ticket)
      {
        owned = fullc;
        owned.ball_runs[5] = ball_run(fh.balls[5]);
        owned.ball_runs[4] = ball_run(fh.balls[4]);
        owned.ball_runs[3] = ball_run(fh.balls[3]);
        owned.ball_runs[2] = ball_run(fh.balls[2]);
        owned.ball_runs[1] = ball_run(fh.balls[1]);
        owned.ball_runs[0] = ball_run(fh.balls[0]);
        this->count6RangeIntersections(owned, winning_combination, full_ball);
        this->count5RangeIntersections(owned, winning_combination, full_ball);
        f += BALL_5_I;
      }
    }
  }

  return &winCounts[0];

/*
  for(int i = 0; i < ticket_runs.length(); i++)
  {
    if(t > ticket_runs[i].ticket_to) break;
    if(t >= ticket_runs[i].ticket_from && t <= ticket_runs[i].ticket_to) return 1;
  }
  ticket_i tickets_not_in_runs = MAX_TICKET - tickets_owned + num_random;
  if(rand() % tickets_not_in_runs < num_random) return 1;
  return 0;
*/
}

ball_i Model::count6RangeIntersections(const ticket_combination &owned, const ticket_combination &winning_combination, const ball_run &full_ball)
{
  ball_i count = 0;
  ticket_combination valid;

  //s s s s s s
  valid = winning_combination;
  count += this->countRangeIntersections(owned, valid);

  return count;
}
ball_i Model::count5RangeIntersections(const ticket_combination &owned, const ticket_combination &winning_combination, const ball_run &full_ball)
{
  ball_i count = 0;
  ticket_combination valid;

  //a s s s s s
  valid = winning_combination;
  valid.ball_runs[0] = full_ball;
  count += this->countRangeIntersections(owned, valid);

  //s a s s s s
  valid = winning_combination;
  valid.ball_runs[1] = full_ball;
  count += this->countRangeIntersections(owned, valid);

  //s s a s s s
  valid = winning_combination;
  valid.ball_runs[2] = full_ball;
  count += this->countRangeIntersections(owned, valid);

  //s s s a s s
  valid = winning_combination;
  valid.ball_runs[3] = full_ball;
  count += this->countRangeIntersections(owned, valid);

  //s s s s a s
  valid = winning_combination;
  valid.ball_runs[4] = full_ball;
  count += this->countRangeIntersections(owned, valid);

  //s s s s s a
  valid = winning_combination;
  valid.ball_runs[5] = full_ball;
  count += this->countRangeIntersections(owned, valid);

  return count;
}

ball_i Model::countRangeIntersections(const ticket_combination &owned, const ticket_combination &valid)
{
  return
    owned.ball_runs[0].countIntersectionWithBallRun(valid.ball_runs[0]) *
    owned.ball_runs[1].countIntersectionWithBallRun(valid.ball_runs[1]) *
    owned.ball_runs[2].countIntersectionWithBallRun(valid.ball_runs[2]) *
    owned.ball_runs[3].countIntersectionWithBallRun(valid.ball_runs[3]) *
    owned.ball_runs[4].countIntersectionWithBallRun(valid.ball_runs[4]) *
    owned.ball_runs[5].countIntersectionWithBallRun(valid.ball_runs[5]);
}

void Model::invalidateOwned()
{
  tickets_owned = 0;
  num_random = 0;
  ticket_runs.removeAll();
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

ticket Model::getTicket(ticket_i t) const
{
  for(int i = 0; i < ticket_runs.length(); i++)
  {
    if((ticket_runs[i].ticket_to-ticket_runs[i].ticket_from)+1 < t)
      t -= (ticket_runs[i].ticket_to-ticket_runs[i].ticket_from)+1;
    else
      return ticket_runs[i].ticket_from+t;
  }
  return null_ticket;
}


/*
      ball indexes : 0 1 2 3 4 5
      ball names   : 1 2 3 4 5 ss

0                  : 1 1 1 1 1 1
1                  : 1 1 1 1 1 2
n<MAX_SUPER_SPHERE : 1 1 1 1 1 n+1
MAX_SUPER_SPHERE-1 : 1 1 1 1 1 MAX_SUPER_SPHERE
MAX_SUPER_SPHERE   : 1 1 1 1 2 1
*/
ticket_human Model::humanReadableTicket(ticket t) const
{
  ticket_human h;
  h.human.super_sphere = t%MAX_SUPER_SPHERE;
  t -= h.human.super_sphere;
  t /= MAX_SUPER_SPHERE;
  for(int i = 4; i >= 0; i--)
  {
    h.balls[i] = t%MAX_BALL;
    t -= h.balls[i];
    t /= MAX_BALL;
  }

  for(int i = 0; i < 6; i++) //wait to add min til now for easier math
    h.balls[i] += MIN_BALL;

  return h;
}

ticket Model::ticketFromHuman(ticket_human h) const
{
  ticket t = 0;
  //clearer to just write it out than use a for loop
  t += (h.human.super_sphere-MIN_BALL);
  t += (h.balls[4]-MIN_BALL)*MAX_SUPER_SPHERE;
  t += (h.balls[3]-MIN_BALL)*MAX_SUPER_SPHERE*MAX_BALL;
  t += (h.balls[2]-MIN_BALL)*MAX_SUPER_SPHERE*MAX_BALL*MAX_BALL;
  t += (h.balls[1]-MIN_BALL)*MAX_SUPER_SPHERE*MAX_BALL*MAX_BALL*MAX_BALL;
  t += (h.balls[0]-MIN_BALL)*MAX_SUPER_SPHERE*MAX_BALL*MAX_BALL*MAX_BALL*MAX_BALL;
  return t;
}










//
// TESTING / DEBUGGING
//

void Model::print()
{
  wtl::log("Dollars: %lld",dollars);
  wtl::log("Owned: %lld",tickets_owned);
  this->printRuns();
}
void Model::printRuns()
{
  for(int i = 0; i < ticket_runs.length(); i++)
    wtl::log("[%lld,%lld]",ticket_runs[i].ticket_from,ticket_runs[i].ticket_to);
}

int Model::run_tests()
{
  //currently using this to actually test the model, not test whether we won
  wtl::log("Test:");

  dollars = 100;
  ticket_i bought = 0;
  ticket t;
  ticket_human h;
  bool success = true;

  //get invalid ticket index
  t = this->getTicket(0);
  success = (t == null_ticket);
  if(success) wtl::log("Succeeded Get invalid!");
  else { wtl::log("Failed Get invalid!"); return 1; }

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
  if(success) wtl::log("Succeeded first purchase!");
  else { wtl::log("Failed first purchase!"); return 1; }

  //get valid ticket index
  t = this->getTicket(0);
  success = (t == 0);
  if(success) wtl::log("Succeeded Get valid!");
  else { wtl::log("Failed Get valid!"); return 1; }

  //get valid end ticket index
  t = this->getTicket(9);
  success = (t == 9);
  if(success) wtl::log("Succeeded Get valid end!");
  else { wtl::log("Failed Get valid end!"); return 1; }

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
  if(success) wtl::log("Succeeded second purchase!");
  else { wtl::log("Failed second purchase!"); return 1; }

  //get valid multi-run ticket index
  t = this->getTicket(14);
  success = (t == 24);
  if(success) wtl::log("Succeeded Get valid multi-run!");
  else { wtl::log("Failed Get valid multi-run!"); return 1; }

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
  if(success) wtl::log("Succeeded front overlap!");
  else { wtl::log("Failed front overlap!"); return 1; }

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
  if(success) wtl::log("Succeeded back overlap!");
  else { wtl::log("Failed back overlap!"); return 1; }

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
  if(success) wtl::log("Succeeded full overlap (ber) !");
  else { wtl::log("Failed full overlap (ber)!"); return 1; }

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
  if(success) wtl::log("Succeeded full overlap (reb) !");
  else { wtl::log("Failed full overlap (reb)!"); return 1; }

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
  if(success) wtl::log("Succeeded Buy 1!");
  else { wtl::log("Failed Buy 1!"); return 1; }

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
  if(success) wtl::log("Succeeded front overlap 1!");
  else { wtl::log("Failed front overlap 1!"); return 1; }

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
  if(success) wtl::log("Succeeded Buy 1 (redux) !");
  else { wtl::log("Failed Buy 1 (redux)!"); return 1; }

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
  if(success) wtl::log("Succeeded back overlap 1!");
  else { wtl::log("Failed back overlap 1!"); return 1; }

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
  if(success) wtl::log("Succeeded takeover!");
  else { wtl::log("Failed takeover!"); return 1; }

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
  if(success) wtl::log("Succeeded run out of money!");
  else { wtl::log("Failed run out of money!"); return 1; }

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
  if(success) wtl::log("Succeeded start next!");
  else { wtl::log("Failed start next!"); return 1; }

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
  if(success) wtl::log("Succeeded finish next!");
  else { wtl::log("Failed finish next!"); return 1; }

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
  if(success) wtl::log("Succeeded fill gap!");
  else { wtl::log("Failed fill gap!"); return 1; }

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
  if(success) wtl::log("Succeeded fill gap!");
  else { wtl::log("Failed fill gap!"); return 1; }

  //lose lottery draw
  success = !this->testWin(200);
  if(success) wtl::log("Succeeded losing draw!");
  else { wtl::log("Failed losing draw!"); return 1; }

  //win lottery draw
  success = this->testWin(199);
  if(success) wtl::log("Succeeded winning draw!");
  else { wtl::log("Failed winning draw!"); return 1; }

  //STATELESS TESTS
  //get human ticket 0
  h = this->humanReadableTicket(0);
  success = (
    h.balls[0] == MIN_BALL &&
    h.balls[1] == MIN_BALL &&
    h.balls[2] == MIN_BALL &&
    h.balls[3] == MIN_BALL &&
    h.balls[4] == MIN_BALL &&
    h.balls[5] == MIN_BALL
    );
  if(success) wtl::log("Succeeded Get human ticket 0!");
  else { wtl::log("Failed Get human ticket 0!"); return 1; }

  //convert human 0 back
  t = this->ticketFromHuman(h);
  success = (t == 0);
  if(success) wtl::log("Succeeded ticket from human 0!");
  else { wtl::log("Failed Get ticket from human 0!"); return 1; }

  //get human ticket MAX_SUPER_SPHERE
  h = this->humanReadableTicket(MAX_SUPER_SPHERE);
  success = (
    h.balls[0] == MIN_BALL &&
    h.balls[1] == MIN_BALL &&
    h.balls[2] == MIN_BALL &&
    h.balls[3] == MIN_BALL &&
    h.balls[4] == MIN_BALL+1 &&
    h.balls[5] == MIN_BALL
    );
  if(success) wtl::log("Succeeded Get human ticket MAX_SUPER_SPHERE!");
  else { wtl::log("Failed Get human ticket MAX_SUPER_SPHERE!"); return 1; }

  //convert human MAX_SUPER_SPHERE back
  t = this->ticketFromHuman(h);
  success = (t == MAX_SUPER_SPHERE);
  if(success) wtl::log("Succeeded ticket from human MAX_SUPER_SPHERE!");
  else { wtl::log("Failed Get ticket from human MAX_SUPER_SPHERE!"); return 1; }

  //get human ticket MAX_BALL*MAX_SUPER_SPHERE
  h = this->humanReadableTicket(MAX_BALL*MAX_SUPER_SPHERE);
  success = (
    h.balls[0] == MIN_BALL &&
    h.balls[1] == MIN_BALL &&
    h.balls[2] == MIN_BALL &&
    h.balls[3] == MIN_BALL+1 &&
    h.balls[4] == MIN_BALL &&
    h.balls[5] == MIN_BALL
    );
  if(success) wtl::log("Succeeded Get human ticket MAX_BALL*MAX_SUPER_SPHERE!");
  else { wtl::log("Failed Get human ticket MAX_BALL*MAX_SUPER_SPHERE!"); return 1; }

  //convert human MAX_BALL*MAX_SUPER_SPHERE back
  t = this->ticketFromHuman(h);
  success = (t == MAX_BALL*MAX_SUPER_SPHERE);
  if(success) wtl::log("Succeeded ticket from human MAX_BALL*MAX_SUPER_SPHERE!");
  else { wtl::log("Failed Get ticket from human MAX_BALL*MAX_SUPER_SPHERE!"); return 1; }

  wtl::log("Success");
  return 0;
}

