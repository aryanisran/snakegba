#include "Intellisense.h"
#include "object.h"

void drawobj(OBJ obj) {
    m3_rect(obj.pos.x - obj.w/2, obj.pos.y + obj.h/2, obj.pos.x + obj.w/2, obj.pos.y - obj.h/2, obj.clr);
}

OBJ initobj(int w, int h, POINT pos, COLOR clr) {
    OBJ obj;
    obj.w = w; obj.h = h; obj.pos = pos; obj.clr = clr;
    return obj;
}