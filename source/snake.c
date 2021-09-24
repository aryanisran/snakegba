#include "Intellisense.h"
#include "snake.h"
#include "object.h"
#include <stdlib.h>

const int w = 10;
const int h = 10;
node_t *snakeptr = NULL;

void addAtTail(node_t *head, OBJ val) {
    node_t *current = head;
    //Point to the tail
    while(current->next != NULL) {
        current = current->next;
    }

    //Now we can add a new variable
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->prev = current;
    current->next->next = NULL;
}

void initSnake() {
    snakeptr = malloc(sizeof(node_t));
    POINT temp;
    temp.x = SCREEN_WIDTH/2;
    temp.y = SCREEN_HEIGHT/2;
    snakeptr->val = initobj(w, h, temp, CLR_LIME);
    snakeptr->next = NULL;
    snakeptr->prev = NULL;
    drawobj(snakeptr->val);
    temp.x = snakeptr->val.pos.x;
    temp.y = snakeptr->val.pos.y + h;
    addAtTail(snakeptr, initobj(w, h, temp, CLR_LIME));
    temp.y = snakeptr->next->val.pos.y + h;
    addAtTail(snakeptr, initobj(w, h, temp, CLR_LIME));
}

void drawSnake() {
    node_t *current = snakeptr;
    while(current != NULL) {
        drawobj(current->val);
        current = current->next;
    }
}

void moveHead(int dX, int dY) {
    if(snakeptr->val.pos.x + dX  + w/2 < SCREEN_WIDTH && snakeptr->val.pos.x + dX- w/2 > 0) {
        if(dX != 0) {
        moveBody();
        }
        snakeptr->val.pos.x += dX;
    }
    if(snakeptr->val.pos.y + dY + h/2 < SCREEN_HEIGHT && snakeptr->val.pos.y + dY - h/2 > 0) {
        if(dY != 0) {
        moveBody();
        }
        snakeptr->val.pos.y += dY;
    }
}

void moveBody() {
    node_t *current = snakeptr;
    //Point to the tail
    while(current->next != NULL) {
        current = current->next;
    }
    //Move the snake from tail up to the head
    while (current->prev != NULL) {
        current->val.pos = current->prev->val.pos;
        current = current->prev;
    }
}
