#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//int xPos, yPos;
//OBJ body;

int main()
{

    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

    // POINT tempPos;
    // tempPos.x = SCREEN_WIDTH/2;
    // tempPos.y = SCREEN_HEIGHT/2;
    // body = initobj(16, 16, tempPos, CLR_WHITE);
    initGame();
    while(1)
    {
        if(restart) {
            initGame();
            restart = false;
        }
        else {
            input();
            update();
        }
    }

    return 0;
}