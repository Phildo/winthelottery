#ifndef _MODEL_H_
#define _MODEL_H_

#include "var_array.h"
#define MAX_TICKET 25022350465ll //25,022,350,465 //max ll is 9,223,372,036,854,775,807
#define TICKET_MASK 0x0000000EFFFFFFFF //max bits required to hold MAX_TICKETS (gah look how much wasted data...)

#define MIN_BALL 1
#define MAX_BALL 59
#define MAX_SUPER_SPHERE 35

//Unit to increment given ball
#define BALL_0_I 1*((59-1)+1)*((59-1)+1)*((59-1)+1)*((59-1)+1)*((59-1)+1)
#define BALL_1_I 1*((59-1)+1)*((59-1)+1)*((59-1)+1)*((59-1)+1)
#define BALL_2_I 1*((59-1)+1)*((59-1)+1)*((59-1)+1)
#define BALL_3_I 1*((59-1)+1)*((59-1)+1)
#define BALL_4_I 1*((59-1)+1)
#define BALL_5_I 1

typedef long long ticket;
typedef long long ticket_i; //index of ticket (must be able to address any ticket)
typedef char ball;
typedef char ball_i;
const ticket null_ticket = -1;
const ticket_i null_ticket_i = -1;
const ball null_ball = -1;
const ball_i null_ball_i = -1;

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
  ball balls[6];
  struct
  {
    ball ball_0; //ball[0] //1-59 (MIN_BALL - MAX_BALL)
    ball ball_1; //ball[1] //1-59
    ball ball_2; //ball[2] //1-59
    ball ball_3; //ball[3] //1-59
    ball ball_4; //ball[4] //1-59
    ball super_sphere; //ball[5] //1-35 (MIN_BALL - MAX_SUPER_SPHERE)
  } human;
};

struct ball_run
{
  ball ball_from;
  ball ball_to;
  ball_run() : ball_from(0), ball_to(0) {};
  ball_run(ball from, ball to) : ball_from(from), ball_to(to) {};
  ball_run(ball b) : ball_from(b), ball_to(b) {};
  ball_i countIntersectionWithBallRun(const ball_run &b) const
  {
    ball big_from = ball_from > b.ball_from ? ball_from : b.ball_from;
    ball small_to = ball_to < b.ball_to ? ball_to : b.ball_to;

    return small_to - big_from > 0 ? small_to - big_from : 0;
  }
};
struct ticket_combination
{
  ball_run ball_runs[6];
  ticket_combination() {};
  ticket_combination(ball_run a, ball_run b, ball_run c, ball_run d, ball_run e, ball_run f) //create from runs
  { ball_runs[0] = a; ball_runs[1] = b; ball_runs[2] = c; ball_runs[3] = d; ball_runs[4] = e; ball_runs[5] = f; };
  ticket_combination(ball a, ball b, ball c, ball d, ball e, ball f) //create from ball_runs
  { ball_runs[0] = ball_run(a); ball_runs[1] = ball_run(b); ball_runs[2] = ball_run(c); ball_runs[3] = ball_run(d); ball_runs[4] = ball_run(e); ball_runs[5] = ball_run(f); };
  ticket_combination(ticket_human t) //create from ticket
  { ball_runs[0] = ball_run(t.balls[0]); ball_runs[1] = ball_run(t.balls[1]); ball_runs[2] = ball_run(t.balls[2]); ball_runs[3] = ball_run(t.balls[3]); ball_runs[4] = ball_run(t.balls[4]); ball_runs[5] = ball_run(t.balls[5]); };
};

class Model
{
  private :
    void print();
    void printRuns();
    ball_i count5RangeIntersections(const ticket_combination &owned, const ticket_combination &winning_combination, const ball_run &full_ball);
    ball_i count6RangeIntersections(const ticket_combination &owned, const ticket_combination &winning_combination, const ball_run &full_ball);
    ball_i countRangeIntersections(const ticket_combination &owned, const ticket_combination &valid);

    ticket_i winCounts[6]; //populated on 'testWin' winCounts[n] = # of owned tickets matching n+1 balls of winning ticket
  public :
    ticket_i dollars;
    ticket_i tickets_owned;
    ticket_i num_random;
    vArray<ticket_run> ticket_runs;

    Model();
    ~Model();

    ticket_i purchaseTicket(ticket t, ticket_i run_length); //returns num purchased
    ticket_i purchaseRandom(ticket_i num); //returns num purchased

    ticket_i* testWin(ticket w); //returns pointer to winCounts (so I don't have to worry about memory management)
    void invalidateOwned();

    ticket getTicket(ticket_i t) const;
    ticket_human humanReadableTicket(ticket t) const;
    ticket ticketFromHuman(ticket_human h) const;

    int run_tests();
};

#endif

