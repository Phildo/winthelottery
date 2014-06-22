#ifndef _RENDERUTILS_H_
#define _RENDERUTILS_H_

struct SDL_Surface;
struct SDL_Rect;

namespace RenderUtils
{
    void load_image(const char* filename, SDL_Surface*& surface);
    void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = 0);
};

#endif

