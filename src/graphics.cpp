#include "graphics.h"

Graphics::Graphics()
{
  //SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer);
  window = SDL_CreateWindow(NULL, 0, 0, 0, 0, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  //clear color
  SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
}

Graphics::~Graphics()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void Graphics::draw(const Sprite& s, SDL_Rect& rect)
{
  SDL_RenderCopy(renderer, s.tex, NULL, &rect);
}

void Graphics::clear()
{
  SDL_RenderClear(renderer);
}

void Graphics::flip()
{
  SDL_RenderPresent(renderer);
}

int Graphics::width()
{
  int w;
  SDL_GetWindowSize(window, &w, NULL);
  return w;
}

int Graphics::height()
{
  int h;
  SDL_GetWindowSize(window, NULL, &h);
  return h;
}

Sprite Graphics::loadSprite(const char* file)
{
  Sprite result;

  SDL_Surface* surf = SDL_LoadBMP(file);
  SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format,0xFF,0x00,0xFF));

  result.w = surf->w;
  result.h = surf->h;
  result.tex = SDL_CreateTextureFromSurface(renderer, surf);

  SDL_FreeSurface(surf);

  return result;
}

