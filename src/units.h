#ifndef _UNITS_H_
#define _UNITS_H_

#include "SDL.h"

namespace Units
{
  //ratios
  const int screen_r = 1;
  const int sprite_r = 4;
  const int block_r = 80;

  //types (probably redundant)
  typedef int screen_p; //1
  typedef int sprite_p; //4
  typedef int block_p; //80

  screen_p spriteToScreen(sprite_p p) { return p/sprite_r*screen_r; }
  SDL_Rect spriteToScreen(sprite_p x, sprite_p y, sprite_p w, sprite_p h) { SDL_Rect r; r.x = x/sprite_r*screen_r; r.y = y/sprite_r*screen_r; r.w = w/sprite_r*screen_r; r.h = h*sprite_r*screen_r; }
  SDL_Rect spriteToScreen(SDL_Rect p) { return spriteToScreen(p.x, p.y, p.w, p.h); }

  block_p spriteToBlock(sprite_p p)  { return p/sprite_r*block_r; }
  SDL_Rect spriteToBlock(sprite_p x, sprite_p y, sprite_p w, sprite_p h) { SDL_Rect r; r.x = x/sprite_r*block_r; r.y = y/sprite_r*block_r; r.w = w/sprite_r*block_r; r.h = h*sprite_r*block_r; }
  SDL_Rect spriteToBlock(SDL_Rect p) { return spriteToBlock(p.x, p.y, p.w, p.h); }

  sprite_p screenToSprite(screen_p p) { return p/screen_r*sprite_r; }
  SDL_Rect screenToSprite(screen_p x, screen_p y, screen_p w, screen_p h) { SDL_Rect r; r.x = x/screen_r*sprite_r; r.y = y/screen_r*sprite_r; r.w = w/screen_r*sprite_r; r.h = h*screen_r*sprite_r; }
  SDL_Rect screenToSprite(SDL_Rect p) { return screenToSprite(p.x, p.y, p.w, p.h); }

  block_p screenToBlock(screen_p p)  { return p/screen_r*block_r; }
  SDL_Rect screenToBlock(block_p x, block_p y, block_p w, block_p h) { SDL_Rect r; r.x = x/screen_r*block_r; r.y = y/screen_r*block_r; r.w = w/screen_r*block_r; r.h = h*screen_r*block_r; }
  SDL_Rect screenToBlock(SDL_Rect p) { return screenToBlock(p.x, p.y, p.w, p.h); }

  screen_p blockToScreen(block_p p)  { return p/block_r*screen_r; }
  SDL_Rect blockToScreen(block_p x, block_p y, block_p w, block_p h) { SDL_Rect r; r.x = x/block_r*screen_r; r.y = y/block_r*screen_r; r.w = w/block_r*screen_r; r.h = h*block_r*screen_r; }
  SDL_Rect blockToScreen(SDL_Rect p) { return blockToScreen(p.x, p.y, p.w, p.h); }

  sprite_p blockToSprite(block_p p)  { return p/block_r*sprite_r; }
  SDL_Rect blockToSprite(block_p x, block_p y, block_p w, block_p h) { SDL_Rect r; r.x = x/block_r*sprite_r; r.y = y/block_r*sprite_r; r.w = w/block_r*sprite_r; r.h = h*block_r*sprite_r; }
  SDL_Rect blockToSprite(SDL_Rect p) { return blockToSprite(p.x, p.y, p.w, p.h); }
};

#endif

