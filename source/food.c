#include "food.h"


POINT foodPos;
bool found = false;

void spawnFood() {
    while(!found) {
        //Place the food at a random position on the screen
        foodPos.x = ((rand() % (22 + 1 - 1) ) + 1) * 10 + 5;
        foodPos.y = ((rand() % (14 + 1 - 1) ) + 1) * 10 + 5;
        node_t *current = snakehead;
        bool overlap = false;
        //Check if the new position is overlapping with the snake, if it is loop and place it at a new random position
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
    //Draw the food on the screen once we found a suitable position
    drawobj(initobj(10, 10, foodPos, CLR_ORANGE));
}