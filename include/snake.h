#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "object.h"

typedef struct node {
   OBJ val;
   struct node* next;
   struct node* prev;
} node_t;

extern node_t *snakehead;
extern node_t *snaketail;

void addAtTail(OBJ val);
void initSnake();
void drawSnake();
void clearSnake();
void moveHead(int dX, int dY);
void moveBody();
bool checkSelfCollision();
bool checkBoundsCollision();
bool checkFoodCollision(POINT pos);
#endif