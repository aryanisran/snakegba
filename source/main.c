#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//int xPos, yPos;
//OBJ body;

int main()
{

    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;
    srand((unsigned) time(NULL));
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