#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "units.h"
//SDL included by units.h

namespace Sprite
{
  const SDL_Rect ball_white   = Units::blockToSprite(0,0,1,1);
  const SDL_Rect ball_red     = Units::blockToSprite(1,0,1,1);
  const SDL_Rect arrow_up     = Units::blockToSprite(2,1,1,1);
  const SDL_Rect arrow_down   = Units::blockToSprite(2,2,1,1);
  const SDL_Rect ticket_left  = Units::blockToSprite(4,0,1,3);
  const SDL_Rect ticket_mid   = Units::blockToSprite(5,0,1,3);
  const SDL_Rect ticket_right = Units::blockToSprite(6,0,1,3);
  const SDL_Rect ball_num_0_  = Units::blockToSprite(0,1,1,1);
  const SDL_Rect ball_num_1_  = Units::blockToSprite(0,2,1,1);
  const SDL_Rect ball_num_2_  = Units::blockToSprite(0,3,1,1);
  const SDL_Rect ball_num_3_  = Units::blockToSprite(0,4,1,1);
  const SDL_Rect ball_num_4_  = Units::blockToSprite(0,5,1,1);
  const SDL_Rect ball_num_5_  = Units::blockToSprite(0,6,1,1);
  const SDL_Rect ball_num__0  = Units::blockToSprite(1,1,1,1);
  const SDL_Rect ball_num__1  = Units::blockToSprite(1,2,1,1);
  const SDL_Rect ball_num__2  = Units::blockToSprite(1,3,1,1);
  const SDL_Rect ball_num__3  = Units::blockToSprite(1,4,1,1);
  const SDL_Rect ball_num__4  = Units::blockToSprite(1,5,1,1);
  const SDL_Rect ball_num__5  = Units::blockToSprite(1,6,1,1);
  const SDL_Rect ball_num__6  = Units::blockToSprite(1,7,1,1);
  const SDL_Rect ball_num__7  = Units::blockToSprite(1,8,1,1);
  const SDL_Rect ball_num__8  = Units::blockToSprite(1,9,1,1);
  const SDL_Rect ball_num__9  = Units::blockToSprite(1,10,1,1);
};

#endif

