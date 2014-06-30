#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "SDL.h"

class Sprite
{
  private:
  public:
    Sprite();

    SDL_Texture* tex;
    Uint16 w;
    Uint16 h;
    void destroyTex();
    int width();
    int height();
};

#endif

