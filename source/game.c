#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int xDir, yDir;
OBJ obj;
bool eaten;
bool restart;

void initGame() {
    xDir = 0;
    yDir = 0;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            POINT tempPos;
            tempPos.x = i * 10 + 5;
            tempPos.y = j * 10 + 5;
            if(i == 0 || j == 0 || i == 23 || j == 15) {
                drawobj(initobj(10, 10, tempPos, CLR_GRAY));
            }
            else {
                drawframe(initobj(10, 10, tempPos, CLR_GRAY));
            }
        }
    }
    
    initSnake();
    drawSnake();
    spawnFood();
}

void input() {
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
}

void update() {
    clearSnake();
    if(checkSelfCollision() || checkBoundsCollision()) {
        restart = true;
        M3_CLEAR();
        return;
    }
    if(checkFoodCollision(foodPos)) {
            obj = snaketail->val;
            drawobj(obj);
            eaten = true;
    }
    moveHead(xDir * 10, yDir * 10);
    drawSnake();
    if(eaten) {
        addAtTail(obj);
        spawnFood();
        eaten = false;
    }
}