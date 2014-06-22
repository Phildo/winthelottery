#include "game.h"
//#include <SDL/SDL.h>
#include "SDL.h"
//#include <iostream>
#include "graphics.h"
//#include "inpututils.h"
//#include "timer.h"
//#include "scene.h"
//#include "mainscene.h"

const int FPS = 60;
const int MS_PER_TICK = 1000/FPS;

Game::Game()
{
  graphics  = new Graphics();
  //timer     = new Timer();
  //mainScene = new MainScene();
  //scene = mainScene;
}

void Game::run()
{

  Uint8 done = 0;
  SDL_Event event;
  while(!done)
  {
    /* Check for events */
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_FINGERDOWN)
      {
        done = 1;
      }
    }

    SDL_Delay(10);
  }

  //int tickMS = 0;
  //bool quit = false;
  //SDL_Event event;
  //Input input;

  //timer->stamp();
  //while(!quit)
  //{
    //tickMS += timer->msSinceStamp();
    //timer->stamp();

    //while(tickMS > MS_PER_TICK && !quit)
    //{
      //tickMS -= MS_PER_TICK;
      //quit = tickInput(event, input);
      //tickLogic(input);
    //}
    //tickGraphics();
  //}
}

bool Game::tickInput(SDL_Event& e, Input& i)
{
  //InputUtils::clearInput(i);
  //while(SDL_PollEvent(&e))
  //{
    //if(e.type == SDL_QUIT) return true;
    //InputUtils::takeInput(e, i);
  //}
  //return false;
}

void Game::tickLogic(const Input& i)
{
  //scene->tick(i);
}

void Game::tickGraphics()
{
  //graphics->clear();
  //scene->render(graphics);
  //graphics->flip();
}

Game::~Game()
{
  delete graphics;
  //delete timer;
  //delete mainScene;
}

