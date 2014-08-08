#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "units.h"
//SDL included by units.h

namespace Sprite
{
  const SDL_Rect ball_white   = Units::blockToScreen(0,0,1,1);
  const SDL_Rect ball_red     = Units::blockToScreen(1,0,1,1);
  const SDL_Rect arrow_up     = Units::blockToScreen(2,1,1,1);
  const SDL_Rect arrow_down   = Units::blockToScreen(2,2,1,1);
  const SDL_Rect ticket_left  = Units::blockToScreen(4,0,3,1);
  const SDL_Rect ticket_mid   = Units::blockToScreen(5,0,3,1);
  const SDL_Rect ticket_right = Units::blockToScreen(6,0,3,1);
  const SDL_Rect ball_num_0_  = Units::blockToScreen(0,1,1,1);
  const SDL_Rect ball_num_1_  = Units::blockToScreen(0,2,1,1);
  const SDL_Rect ball_num_2_  = Units::blockToScreen(0,3,1,1);
  const SDL_Rect ball_num_3_  = Units::blockToScreen(0,4,1,1);
  const SDL_Rect ball_num_4_  = Units::blockToScreen(0,5,1,1);
  const SDL_Rect ball_num_5_  = Units::blockToScreen(0,6,1,1);
  const SDL_Rect ball_num__0  = Units::blockToScreen(1,1,1,1);
  const SDL_Rect ball_num__1  = Units::blockToScreen(1,2,1,1);
  const SDL_Rect ball_num__2  = Units::blockToScreen(1,3,1,1);
  const SDL_Rect ball_num__3  = Units::blockToScreen(1,4,1,1);
  const SDL_Rect ball_num__4  = Units::blockToScreen(1,5,1,1);
  const SDL_Rect ball_num__5  = Units::blockToScreen(1,6,1,1);
  const SDL_Rect ball_num__6  = Units::blockToScreen(1,7,1,1);
  const SDL_Rect ball_num__7  = Units::blockToScreen(1,8,1,1);
  const SDL_Rect ball_num__8  = Units::blockToScreen(1,9,1,1);
  const SDL_Rect ball_num__9  = Units::blockToScreen(1,10,1,1);
};

#endif

