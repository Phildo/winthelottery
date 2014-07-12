#ifndef _GAME_H_
#define _GAME_H_

class Graphics;
class Model;

union SDL_Event;

class Game
{
  private:
    Graphics* graphics;
    Model* model;

  public:
    Game();
    ~Game();

    void run();
};

#endif

