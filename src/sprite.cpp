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

