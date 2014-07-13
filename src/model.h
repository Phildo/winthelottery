#ifndef _MODEL_H_
#define _MODEL_H_

#include "var_array.h"
#define MAX_TICKET 25022350465ll //25,022,350,465 //max ll is 9,223,372,036,854,775,807
#define TICKET_MASK 0x0000000EFFFFFFFF //max bits required to hold MAX_TICKETS (gah look how much wasted data...)

#define MIN_BALL 1
#define MAX_BALL 59
#define MAX_SUPER_SPHERE 35

typedef long long ticket;
typedef long long ticket_i; //index of ticket (must be able to address any ticket)
const ticket null_ticket = -1;
const ticket_i null_ticket_i = -1;

struct ticket_run
{
  ticket ticket_from;
  ticket ticket_to;
  ticket_run() : ticket_from(0), ticket_to(0) {};
  ticket_run(ticket from, ticket to) : ticket_from(from), ticket_to(to) {};
};

//don't store these en masse- just use for simpler human readability
//even though these are technically more space efficient, a long long is easier to do math on
union ticket_human
{
  unsigned char ball[6];
  struct
  {
    unsigned char ball_1; //1-59 (MIN_BALL - MAX_BALL)
    unsigned char ball_2; //1-59
    unsigned char ball_3; //1-59
    unsigned char ball_4; //1-59
    unsigned char ball_5; //1-59
    unsigned char super_sphere; //1-35 (MIN_BALL - MAX_SUPER_SPHERE)
  } human;
};

class Model
{
  private :
    void print();
    void printRuns();

  public :
    ticket_i dollars;
    ticket_i tickets_owned;
    ticket_i num_random;
    vArray<ticket_run> ticket_runs;

    Model();
    ~Model();

    ticket_i purchaseTicket(ticket t, ticket_i run_length); //returns num purchased
    ticket_i purchaseRandom(ticket_i num); //returns num purchased

    int testWin(ticket t);
    void invalidateOwned();

    ticket getTicket(ticket_i t);
    ticket_human humanReadableTicket(ticket t);
    ticket ticketFromHuman(ticket_human h);

    int run_tests();
};

#endif

