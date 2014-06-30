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

int Sprite::width()
{
  int w;
  SDL_QueryTexture(tex, NULL, NULL, &w, NULL);
  return w;
}

int Sprite::height()
{
  int h;
  SDL_QueryTexture(tex, NULL, NULL, NULL, &h);
  return h;
}

