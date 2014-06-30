#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "sprite.h"
#include "SDL.h"

class Graphics
{
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
  public:
    Graphics();
    ~Graphics();

    void draw(const Sprite& s, SDL_Rect& dest);
    void clear();
    void flip();

    int height();
    int width();

    Sprite loadSprite(const char* file);
};

#endif

