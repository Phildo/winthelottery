#ifndef _GAME_H_
#define _GAME_H_

class Graphics;
//class Timer;
//class Scene;
//class MainScene;

union SDL_Event;
//struct Input;

class Game
{
  private:
    Graphics* graphics;
    //Timer* timer;
    //Scene* scene;

    //MainScene* mainScene;

    //bool tickInput(SDL_Event& e, Input& i);
    //void tickLogic(const Input& i);
    //void tickGraphics();

  public:
    Game();
    ~Game();

    void run();
};

#endif

