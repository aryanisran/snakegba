#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "object.h"

typedef struct node {
   OBJ val;
   struct node* next;
   struct node* prev;
} node_t;

void addAtTail(OBJ val);
void initSnake();
void drawSnake();
void clearSnake();
void moveHead(int dX, int dY);
void moveBody();
#endif