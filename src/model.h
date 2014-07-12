#ifndef _MODEL_H_
#define _MODEL_H_

#include "var_array.h"
#define MAX_TICKET 25022350465 //25,022,350,465 //max ll is 9,223,372,036,854,775,807
#define TICKET_MASK 0x0000000EFFFFFFFF //max bits required to hold MAX_TICKETS (gah look how much wasted data...)

typedef long long ticket;
typedef long long ticket_i; //index of ticket (must be able to address any ticket)

struct ticket_run
{
  ticket ticket_from;
  ticket ticket_to;
  ticket_run(ticket from, ticket to) : ticket_from(from), ticket_to(to) {};
}

class Model
{
  private :

  public :
    ticket_i dollars;
    ticket_i tickets_owned;
    vArray<ticket_run> ticket_runs;
    ticket_i num_random;

    ticket_i purchaseTicket(ticket t, ticket_i run); //returns num purchased
    ticket_i purchaseRandom(ticket_i num); //returns num purchased

    ticket getTicket(ticket_i t);

    int test(ticket t);
};

#endif

