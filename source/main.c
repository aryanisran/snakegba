#include "snake.h"

int xDir, yDir;
//int xPos, yPos;
//OBJ body;

int main()
{

    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

    // POINT tempPos;
    // tempPos.x = SCREEN_WIDTH/2;
    // tempPos.y = SCREEN_HEIGHT/2;
    // body = initobj(16, 16, tempPos, CLR_WHITE);
    xDir = 0;
    yDir = 0;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            POINT tempPos;
            tempPos.x = i * 10 + 5;
            tempPos.y = j * 10 + 5;
            drawframe(initobj(10, 10, tempPos, CLR_GRAY));
        }
    }
    
    initSnake();
    drawSnake();
    while(1)
    {
        for (int i = 0; i < 10; i++)
        {
            vid_vsync();
            key_poll();
            if(key_tri_horz() != 0) {
                if(xDir == 0) {
                    xDir = key_tri_horz();
                    yDir = 0;
                }
            }
            if(key_tri_vert() != 0) {
                if(yDir == 0) {
                    yDir = key_tri_vert();
                    xDir = 0;
                }
            }
        }
        clearSnake();
        moveHead(xDir * 10, yDir * 10);
        drawSnake();
    }

    return 0;
}