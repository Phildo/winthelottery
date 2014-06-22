#include "renderutils.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void RenderUtils::load_image(const char* filename, SDL_Surface*& surface)
{
  SDL_Surface *loadedImage = NULL;
  loadedImage = IMG_Load(filename);

  if(loadedImage != NULL)
  {
    surface = SDL_DisplayFormatAlpha(loadedImage);
    SDL_FreeSurface(loadedImage);
  }
}

void RenderUtils::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface(source, clip, destination, &offset);
}

