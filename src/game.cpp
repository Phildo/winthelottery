#include "game.h"
#include "graphics.h"
#include "model.h"
#include "sprite.h"
#include "logger.h"
#include <SDL.h>

const int FPS = 60;
const int MS_PER_TICK = 1000/FPS;

Game::Game()
{
  graphics = new Graphics();
  model = new Model();
}

void Game::run()
{
  wtl_log("Begin!");
  Uint8 done = 0;
  SDL_Event event;

  float x, y;
  while(!done)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        done = 1;
      }
      else if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
      {
        x = (float)event.button.x/(float)graphics->winWidth();
        y = (float)event.button.y/(float)graphics->winHeight();
        wtl_log("mouse");
      }
      else if(event.type == SDL_FINGERDOWN)
      {
        x = event.tfinger.x;
        y = event.tfinger.y;
        wtl_log("finger");
      }
    }

    graphics->clear();

    //ticket
    SDL_Rect destRect = Units::blockToScreen(0, 0, 1, 3);
    graphics->draw(Sprite::ticket_left,destRect);

    //wtl_log("destRect(%d,%d,%d,%d), ticket_left(%d,%d,%d,%d)",destRect.x,destRect.y,destRect.w,destRect.h,Sprite::ticket_left.x,Sprite::ticket_left.y,Sprite::ticket_left.w,Sprite::ticket_left.h);

    destRect.x = Units::blockToScreen(1);
    graphics->draw(Sprite::ticket_mid,destRect);
    destRect.x = Units::blockToScreen(2);
    graphics->draw(Sprite::ticket_mid,destRect);
    destRect.x = Units::blockToScreen(3);
    graphics->draw(Sprite::ticket_mid,destRect);
    destRect.x = Units::blockToScreen(4);
    graphics->draw(Sprite::ticket_mid,destRect);
    destRect.x = Units::blockToScreen(5);
    graphics->draw(Sprite::ticket_mid,destRect);
    destRect.x = Units::blockToScreen(6);
    graphics->draw(Sprite::ticket_mid,destRect);

    destRect.x = Units::blockToScreen(7);
    graphics->draw(Sprite::ticket_right,destRect);

    //balls
    destRect.x = Units::blockToScreen(1)/2;
    destRect.y = Units::blockToScreen(1)+Units::blockToScreen(1)/2;
    destRect.w = Units::blockToScreen(1);
    destRect.h = Units::blockToScreen(1);
    graphics->draw(Sprite::ball_white,destRect);
    graphics->draw(Sprite::ball_num_0_,destRect);
    graphics->draw(Sprite::ball_num__9,destRect);

    destRect.x = Units::blockToScreen(1)+Units::blockToScreen(1)/2;
    graphics->draw(Sprite::ball_white,destRect);
    graphics->draw(Sprite::ball_num_1_,destRect);
    graphics->draw(Sprite::ball_num__8,destRect);

    destRect.x = Units::blockToScreen(2)+Units::blockToScreen(1)/2;
    graphics->draw(Sprite::ball_white,destRect);
    graphics->draw(Sprite::ball_num_2_,destRect);
    graphics->draw(Sprite::ball_num__7,destRect);

    destRect.x = Units::blockToScreen(3)+Units::blockToScreen(1)/2;
    graphics->draw(Sprite::ball_white,destRect);
    graphics->draw(Sprite::ball_num_3_,destRect);
    graphics->draw(Sprite::ball_num__6,destRect);

    destRect.x = Units::blockToScreen(4)+Units::blockToScreen(1)/2;
    graphics->draw(Sprite::ball_white,destRect);
    graphics->draw(Sprite::ball_num_4_,destRect);
    graphics->draw(Sprite::ball_num__5,destRect);

    destRect.x = Units::blockToScreen(5)+Units::blockToScreen(1)/2;
    graphics->draw(Sprite::ball_red,destRect);
    graphics->draw(Sprite::ball_num_5_,destRect);
    graphics->draw(Sprite::ball_num__4,destRect);

    graphics->flip();
    SDL_Delay(10);
  }
}

Game::~Game()
{
  delete graphics;
  delete model;
}

