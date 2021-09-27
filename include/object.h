#ifndef _OBJECT_H_
#define _OBJECT_H_
#include "tonc.h"

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