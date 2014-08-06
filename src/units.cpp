#include "units.h"
#include "logger.h"

screen_p Units::spriteToScreen(sprite_p p) { return p*sprite_r/screen_r; }
SDL_Rect Units::spriteToScreen(sprite_p x, sprite_p y, sprite_p w, sprite_p h) { SDL_Rect r; r.x = x*sprite_r/screen_r; r.y = y*sprite_r/screen_r; r.w = w*sprite_r/screen_r; r.h = h*sprite_r/screen_r; return r; }
SDL_Rect Units::spriteToScreen(SDL_Rect p) { return spriteToScreen(p.x, p.y, p.w, p.h); }

block_p Units::spriteToBlock(sprite_p p)  { return p*sprite_r/block_r; }
SDL_Rect Units::spriteToBlock(sprite_p x, sprite_p y, sprite_p w, sprite_p h) { SDL_Rect r; r.x = x*sprite_r/block_r; r.y = y*sprite_r/block_r; r.w = w*sprite_r/block_r; r.h = h*sprite_r/block_r; return r; }
SDL_Rect Units::spriteToBlock(SDL_Rect p) { return spriteToBlock(p.x, p.y, p.w, p.h); }

sprite_p Units::screenToSprite(screen_p p) { return p*screen_r/sprite_r; }
SDL_Rect Units::screenToSprite(screen_p x, screen_p y, screen_p w, screen_p h) { SDL_Rect r; r.x = x*screen_r/sprite_r; r.y = y*screen_r/sprite_r; r.w = w*screen_r/sprite_r; r.h = h*screen_r/sprite_r; return r; }
SDL_Rect Units::screenToSprite(SDL_Rect p) { return screenToSprite(p.x, p.y, p.w, p.h); }

block_p Units::screenToBlock(screen_p p)  { return p*screen_r/block_r; }
SDL_Rect Units::screenToBlock(block_p x, block_p y, block_p w, block_p h) { SDL_Rect r; r.x = x*screen_r/block_r; r.y = y*screen_r/block_r; r.w = w*screen_r/block_r; r.h = h*screen_r/block_r; return r; }
SDL_Rect Units::screenToBlock(SDL_Rect p) { return screenToBlock(p.x, p.y, p.w, p.h); }

screen_p Units::blockToScreen(block_p p)  { return p*block_r/screen_r; }
SDL_Rect Units::blockToScreen(block_p x, block_p y, block_p w, block_p h) { SDL_Rect r; r.x = x*block_r/screen_r; r.y = y*block_r/screen_r; r.w = w*block_r/screen_r; r.h = h*block_r/screen_r; return r; }
SDL_Rect Units::blockToScreen(SDL_Rect p) { return blockToScreen(p.x, p.y, p.w, p.h); }

sprite_p Units::blockToSprite(block_p p)  { return p*block_r/sprite_r; }
SDL_Rect Units::blockToSprite(block_p x, block_p y, block_p w, block_p h) { SDL_Rect r; r.x = x*block_r/sprite_r; r.y = y*block_r/sprite_r; r.w = w*block_r/sprite_r; r.h = h*block_r/sprite_r; return r; }
SDL_Rect Units::blockToSprite(SDL_Rect p) { return blockToSprite(p.x, p.y, p.w, p.h); }

