#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
  private:
    int x;
    int y;
  public:
    Player(int x, int y);
    ~Player();
    int getX();
    int getY();
    void move(int up, int down, int left, int right);
};

#endif

