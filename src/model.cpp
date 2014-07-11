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
  return bought;




  //only possible conflicts are between i_start and i_end, inclusive
  int i_start = 0; //first ticket that ends further= than I start
  while(i_start < l && ticket_runs[i_start].ticket_to < run.ticket_from) i_start++;
  int i_end = l-1; //last ticket that starts before= I end
  while(i_end >= 0 && ticket_runs[i_end].ticket_from > run.ticket_to) i_end--;

  if(i_start == l) //no tickets exist beyond run start- safe to just add
  {
    if(dollars > run_length) run_length = dollars;
    dollars -= run_length;
    run.ticket_to = run.ticket_from+run_length-1;
    ticket_runs.add(run);
    return run_length;
  }
  if(i_end < 0) //no tickets exist before run end- safe to inject at front
  {
    if(dollars > run_length) run_length = dollars;
    dollars -= run_length;
    run.ticket_to = run.ticket_from+run_length-1;
    ticket_runs.insert(0,run);
    return run_length;
  }

  if(ticket_runs[i_start].ticket_from < run.ticket_to) //safe to inject before
  {
    if(dollars > run_length) run_length = dollars;
    dollars -= run_length;
    run.ticket_to = run.ticket_from+run_length-1;
    ticket_runs.insert(i_start,run);
    return run_length;
  }
  if(ticket_runs[i_end].ticket_to < run.ticket_from) //safe to inject after
  {
    if(dollars > run_length) run_length = dollars;
    dollars -= run_length;
    run.ticket_to = run.ticket_from+run_length-1;
    ticket_runs.insert(i_end+1,run);
    return run_length;
  }


}

ticket_i Model::purchaseRandom(ticket_i num)
{
}

ticket Model::getTicket(ticket_i t)
{
}

int Model::test(ticket t)
{
}

