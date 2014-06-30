#ifndef _INPUTUTILS_H_
#define _INPUTUTILS_H_

union SDL_Event;

struct Input
{
  bool key;//any

  bool up;
  bool down;
  bool left;
  bool right;
};

namespace InputUtils
{
    void clearInput(Input& i);
    void takeInput(const SDL_Event& e, Input& i);
};

#endif

