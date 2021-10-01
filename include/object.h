#ifndef _OBJECT_H_
#define _OBJECT_H_
#include "tonc.h"

/*GBA mode 3 directly changes the colors of the pixels on the screen, tonc's function to draw rectangles in mode 3
takes the corners of the rectangle to draw it, we use a struct that contains the width, height and position of a "gameObject" to make things easier for us
*/
typedef struct obj {
    int w;
    int h;
    POINT pos;
    COLOR clr;
} OBJ;

void drawobj(OBJ obj);
void drawframe(OBJ obj);
void clearobj(OBJ obj);
OBJ initobj(int w, int h, POINT pos, COLOR clr);

#endif