#include "model.h"

//absolutely covered with edge cases
ticket_i Model::purchaseTicket(ticket t, ticket_i run_length)
{
  if(t+run_length-1 > MAX_TICKET) run_length = MAX_TICKET-t+1;
  ticket_run run(t, t+run_length-1); //the run to attempt purchase

  int l = ticket_runs.length();
  ticket_i bought = 0;

  int i = 0; //first ticket that starts after run starts
  while(i < l && ticket_runs[i].ticket_from < run.ticket_from) i++;

  if(i > 0 && run.ticket_from < ticket_runs[i-1].ticket_to)
    i--;
  else
  {
    ticket_run tmp(run.ticket_from,run.ticket_from);
    bought++;
    dollars--;
    ticket_runs.insert(i,tmp);
  }

  //at this point, ticket_runs[i] is a ticket with run length at least 1 (already payed for)
  //and must be extended for the full length of the run, potentially merging with further runs

  ticket_i bought_til = ticket_runs[i].ticket_to;
  while(bought_til < runs.ticket_to)
  {
    ticket_i straight_shot_max = (dollars > runs.ticket_to-bought_til) ? bought_til+dollars : runs.ticket_to;
    if(i == ticket_runs.length() || ticket_runs[i+1].ticket_from > straight_shot_max)
    {
      bought  += straight_shot_max-bought_til;
      dollars -= straight_shot_max-bought_til;
      ticket_runs[i].ticket_to = straight_shot_max;
      bought_til = ticket_runs[i].ticket_to;

      tickets_owned += bought;
      return bought;
    }
    else
    {
      bought  += ticket_runs[i+1].ticket_from-bought_til;
      dollars -= ticket_runs[i+1].ticket_from-bought_til;
      ticket_runs[i].ticket_to = ticket_runs[i+1].ticket_to;
      bought_til = ticket_runs[i].ticket_to;
      ticket_runs.remove(i+1);
      i++;
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

int Model::test(ticket t)
{
}

