#include "inpututils.h"

#include <SDL/SDL.h>

void InputUtils::clearInput(Input& i)
{
  i.key   = false;

  i.up    = false;
  i.down  = false;
  i.left  = false;
  i.right = false;
}

void InputUtils::takeInput(const SDL_Event& e, Input& i)
{
  if(e.type == SDL_KEYDOWN)
  {
    switch(e.key.keysym.sym)
    {
      case SDLK_UP:    case SDLK_w: i.up    = true; i.key = true; break;
      case SDLK_LEFT:  case SDLK_a: i.left  = true; i.key = true; break;
      case SDLK_DOWN:  case SDLK_s: i.down  = true; i.key = true; break;
      case SDLK_RIGHT: case SDLK_d: i.right = true; i.key = true; break;
      default: break;
    }
  }
  else if(e.type == SDL_KEYUP)
  {
    switch(e.key.keysym.sym)
    {
      case SDLK_UP:    case SDLK_w: i.up    = false; break;
      case SDLK_LEFT:  case SDLK_a: i.left  = false; break;
      case SDLK_DOWN:  case SDLK_s: i.down  = false; break;
      case SDLK_RIGHT: case SDLK_d: i.right = false; break;
      default: break;
    }
    i.key = i.up || i.left || i.down || i.right;
  }
}

