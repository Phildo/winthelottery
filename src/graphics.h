#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "SDLi.h"

class Graphics
{
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* tex;
  public:
    Graphics();
    ~Graphics();

    void draw(const SDL_Rect& src, const SDL_Rect& dest);
    void clear();
    void flip();

    int winHeight();
    int winWidth();
    int texHeight();
    int texWidth();

};

#endif

