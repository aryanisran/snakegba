#include "food.h"


POINT foodPos;
bool found = false;

void spawnFood() {
    while(!found) {
        foodPos.x = ((rand() % (22 + 1 - 1) ) + 1) * 10 + 5;
        foodPos.y = ((rand() % (14 + 1 - 1) ) + 1) * 10 + 5;
        node_t *current = snakehead;
        bool overlap = false;
        while(current != NULL) {
            if(current->val.pos.x == foodPos.x && current->val.pos.y == foodPos.y) {
                overlap = true;
            }
            current = current->next;
        }
        if(!overlap) {
            found = true;
        }
    }
    found = false;
    drawobj(initobj(10, 10, foodPos, CLR_GREEN));
}