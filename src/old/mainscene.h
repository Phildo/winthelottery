#ifndef _MAIN_SCENE_H_
#define _MAIN_SCENE_H_

#include "scene.h"

class Player;
class PlayerRenderer;
struct Input;

class MainScene : public Scene
{
  private:
    Player* player;
    PlayerRenderer* playerRenderer;

    int ticksSinceLastMove;
  public:
    MainScene();
    ~MainScene();

    void render(const Graphics* g) const;
    void tick(const Input& i);
};

#endif

