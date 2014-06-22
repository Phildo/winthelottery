#include "sprite.h"

Sprite::Sprite()
{
  tex = NULL;
  w = 0;
  h = 0;
}

void Sprite::destroyTex()
{
  SDL_DestroyTexture(tex);
}

Sprite loadSprite(const char* file, SDL_Renderer* renderer)
{
  Sprite result;

  SDL_Surface* temp = SDL_LoadBMP(file);
  result.w = temp->w;
  result.h = temp->h;
  result.tex = SDL_CreateTextureFromSurface(renderer, temp);
  SDL_FreeSurface(temp);

  return result;
}

