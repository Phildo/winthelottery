#include "playerrenderer.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "graphics.h"

PlayerRenderer::PlayerRenderer()
{
  RenderUtils::load_image("assets/proud_face.png", smile);
}

void PlayerRenderer::render(const void* r, const Graphics* g) const
{
  Player* p = (Player*)r;
  RenderUtils::apply_surface(p->getX()*16,p->getY()*16,smile,g->getScreen());
}

PlayerRenderer::~PlayerRenderer()
{

}

