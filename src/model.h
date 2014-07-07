#ifndef _MODEL_H_
#define _MODEL_H_

typedef unsigned long ticket;
typedef unsigned long ticket_index;

class Model
{
  private :

  public :
    int dollars;
    ticket *tickets;
    ticket *run_starts;
    ticket *run_lengths;
    ticket num_random;

    int purchaseTicket(ticket t);
    int purchaseRun(ticket start, ticket_index length);
    int purchaseRandom(ticket_index num);

    ticket getTicket(ticket_index t);

    int test(ticket t);
};

#endif

