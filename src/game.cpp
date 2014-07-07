#include "game.h"
#include "graphics.h"
#include "var_array.h"
#include "SDL.h"
#include <android/log.h>

const int FPS = 60;
const int MS_PER_TICK = 1000/FPS;

Game::Game()
{
  graphics = new Graphics();
}

void Game::run()
{
  Uint8 done = 0;
  SDL_Event event;

  Sprite sp = graphics->loadSprite("test10.bmp");
  __android_log_print(ANDROID_LOG_INFO, "WTL", "Begin!");
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
        x = (float)event.button.x/(float)graphics->width();
        y = (float)event.button.y/(float)graphics->width();
      }
      else if(event.type == SDL_FINGERDOWN)
      {
        x = event.tfinger.x;
        y = event.tfinger.y;
      }
    }

    graphics->clear();
    SDL_Rect destRect = {100, 100, 100, 100};
    graphics->draw(sp,destRect);
    graphics->flip();

    SDL_Delay(10);
  }
  sp.destroyTex();
}

Game::~Game()
{
  delete graphics;
}

