#ifndef _SCENE_H_
#define _SCENE_H_

class Graphics;
struct Input;
class Scene
{
  public:
    virtual ~Scene() {};
    virtual void render(const Graphics* g) const = 0;
    virtual void tick(const Input& i) = 0;
};

#endif

