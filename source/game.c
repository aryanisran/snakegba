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

    //Draw the grid that the snake game will be played on
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
    //This for loop slows down our game, so that one frame of our game occurs every 10 frames of the GBA
    for (int i = 0; i < 10; i++)
        {
            vid_vsync();
            key_poll();
            //Set our direction variables to the current input using tribools
            //Only change the direction the snake is going if player is not trying to make a u-turn
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
        //When the snake head collides with food, draw the new tail BEFORE the snake moves
        obj = snaketail->val;
        drawobj(obj);
        eaten = true;
    }
    moveHead(xDir * 10, yDir * 10);
    drawSnake();
    if(eaten) {
        //Only after the snake moves, we link the new tail to the linked list, making it move with the rest of the snake
        addAtTail(obj);
        spawnFood();
        eaten = false;
    }
}