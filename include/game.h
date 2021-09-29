#ifndef _GAME_H_
#define _GAME_H_

#include "tonc.h"
#include "object.h"
#include "snake.h"
#include "food.h"

extern bool restart;
void initGame();
void input();
void update();
#endif