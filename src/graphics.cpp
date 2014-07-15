#include "graphics.h"

Graphics::Graphics()
{
  //SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer);
  window = SDL_CreateWindow(NULL, 0, 0, 0, 0, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  //clear color
  SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);

  //load tex
  SDL_Surface* surf = SDL_LoadBMP("tex.bmp");
  SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format,0xFF,0x00,0xFF));
  tex = SDL_CreateTextureFromSurface(renderer, surf);
  SDL_FreeSurface(surf);
}

Graphics::~Graphics()
{
  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void Graphics::draw(const SDL_Rect& src, const SDL_Rect& dest)
{
  SDL_RenderCopy(renderer, tex, &src, &dest);
}

void Graphics::clear()
{
  SDL_RenderClear(renderer);
}

void Graphics::flip()
{
  SDL_RenderPresent(renderer);
}

int Graphics::winWidth()  { int w; SDL_GetWindowSize(window, &w, NULL); return w; }
int Graphics::winHeight() { int h; SDL_GetWindowSize(window, NULL, &h); return h; }
int Graphics::texWidth()  { int w; SDL_QueryTexture(tex, NULL, NULL, &w, NULL); return w; }
int Graphics::texHeight() { int h; SDL_QueryTexture(tex, NULL, NULL, NULL, &h); return h; }

