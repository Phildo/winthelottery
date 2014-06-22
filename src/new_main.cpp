#include "game.h"
#include <SDL/SDL.h>

int main(int argc, char **args)
{
  SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS);

  //Game g;
  //g.run();
  //delete g;

  SDL_Quit();
  return 0;
}

