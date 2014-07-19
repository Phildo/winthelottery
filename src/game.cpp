#include "game.h"
#include "graphics.h"
#include "model.h"
#include "sprite.h"
#include "SDL.h"
#include <android/log.h>

const int FPS = 60;
const int MS_PER_TICK = 1000/FPS;

Game::Game()
{
  graphics = new Graphics();
  //model = new Model();
}

void Game::run()
{
  __android_log_print(ANDROID_LOG_INFO, "WTL", "Begin!");
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
      }
      else if(event.type == SDL_FINGERDOWN)
      {
        x = event.tfinger.x;
        y = event.tfinger.y;
      }
    }

    graphics->clear();

    //ticket
    SDL_Rect destRect = Units::blockToScreen(0, 0, 1, 3);
    graphics->draw(Sprite::ticket_left,destRect);

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

    destRect.x = Units::blockToScreen(2);
    graphics->draw(Sprite::ball_white,destRect);
    graphics->draw(Sprite::ball_num_2_,destRect);
    graphics->draw(Sprite::ball_num__7,destRect);

    destRect.x = Units::blockToScreen(2)+Units::blockToScreen(1)/2;
    graphics->draw(Sprite::ball_white,destRect);
    graphics->draw(Sprite::ball_num_3_,destRect);
    graphics->draw(Sprite::ball_num__6,destRect);

    destRect.x = Units::blockToScreen(3);
    graphics->draw(Sprite::ball_white,destRect);
    graphics->draw(Sprite::ball_num_4_,destRect);
    graphics->draw(Sprite::ball_num__5,destRect);

    destRect.x = Units::blockToScreen(3)+Units::blockToScreen(1)/2;
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
  //delete model;
}

