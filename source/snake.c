#include "Intellisense.h"
#include "snake.h"
#include <stdlib.h>

const int w = 10;
const int h = 10;

node_t *snakehead = NULL;
node_t *snaketail = NULL;

void addAtTail(OBJ val) {
    snaketail->next = (node_t *) malloc(sizeof(node_t));
    snaketail->next->val = val;
    snaketail->next->prev = snaketail;
    snaketail = snaketail->next;
    snaketail->next->next = NULL;
}

void initSnake() {
    snakehead = malloc(sizeof(node_t));
    POINT temp;
    temp.x = 35;
    temp.y = 15;
    snakehead->val = initobj(w, h, temp, CLR_LIME);
    snakehead->next = NULL;
    snakehead->prev = NULL;
    snaketail = snakehead;
    drawobj(snakehead->val);
    temp.x = snakehead->val.pos.x - w;
    temp.y = snakehead->val.pos.y;
    addAtTail(initobj(w, h, temp, CLR_LIME));
    temp.x = snakehead->next->val.pos.x - w;
    addAtTail(initobj(w, h, temp, CLR_LIME));
}

void drawSnake() {
    node_t *current = snakehead;
    while(current != NULL) {
        drawobj(current->val);
        current = current->next;
    }
}

void moveHead(int dX, int dY) {
    if(snakehead->val.pos.x + dX  + w/2 < SCREEN_WIDTH && snakehead->val.pos.x + dX- w/2 > 0) {
        if(dX != 0) {
        moveBody();
        }
        snakehead->val.pos.x += dX;
    }
    if(snakehead->val.pos.y + dY + h/2 < SCREEN_HEIGHT && snakehead->val.pos.y + dY - h/2 > 0) {
        if(dY != 0) {
        moveBody();
        }
        snakehead->val.pos.y += dY;
    }
}

void moveBody() {
    node_t *current = snaketail;
    //Move the snake from tail up to the head
    while (current->prev != NULL) {
        current->val.pos = current->prev->val.pos;
        current = current->prev;
    }
}

void clearSnake() {
    clearobj(snaketail->val);
}

bool checkSelfCollision() {
    node_t *current = snakehead->next;
    while(current != NULL) {
        if(current->val.pos.x == snakehead->val.pos.x && current->val.pos.y == snakehead->val.pos.y) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool checkBoundsCollision() {
    if(snakehead->val.pos.x <= 5 || snakehead->val.pos.x >= 255 || snakehead->val.pos.y <= 0 || snakehead->val.pos.y >= 155) {
        return true;
    }
    return false;
}

bool checkFoodCollision(POINT pos) {
    if(snakehead->val.pos.x == pos.x && snakehead->val.pos.y == pos.y) {
        return true;
    }
    return false;
}