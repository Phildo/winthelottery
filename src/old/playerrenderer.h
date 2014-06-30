#ifndef _PLAYERRENDERER_H_
#define _PLAYERRENDERER_H_

#include "renderer.h"

class PlayerRenderer : public Renderer
{
  private:
    SDL_Surface *smile;
  public:
    PlayerRenderer();
    ~PlayerRenderer();
    void render(const void* r, const Graphics* g) const;
};

#endif

