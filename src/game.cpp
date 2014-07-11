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

  vArray<Sprite> varay;
  Sprite sp1 = graphics->loadSprite("test10.bmp");
  Sprite sp2 = graphics->loadSprite("test10.bmp");
  varay.add(sp1);
  varay.add(sp2);
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
    for(int i = 0; i < varay.length(); i++)
      graphics->draw(varay[i],destRect);
    graphics->flip();

    SDL_Delay(10);
  }
  for(int i = 0; i < varay.length(); i++)
    varay[i].destroyTex();
}

Game::~Game()
{
  delete graphics;
}

