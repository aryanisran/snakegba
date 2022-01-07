#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//int xPos, yPos;
//OBJ body;

int main()
{
    //Set the GBA display to mode 3
    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;
    //Seed the pseudorandom number generator
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