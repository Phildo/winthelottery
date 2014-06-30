#include "player.h"

Player::Player(int x, int y)
{
  this->x = x;
  this->y = y;
}

int Player::getX()
{
  return x;
}

int Player::getY()
{
  return y;
}

void Player::move(int up, int down, int left, int right)
{
  x += right-left;
  y += down-up;
}

Player::~Player()
{

}

