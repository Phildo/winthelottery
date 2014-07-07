#ifndef _GAME_H_
#define _GAME_H_

class Graphics;

union SDL_Event;

class Game
{
  private:
    Graphics* graphics;

  public:
    Game();
    ~Game();

    void run();
};

#endif

