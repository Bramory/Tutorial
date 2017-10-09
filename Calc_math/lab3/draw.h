#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <GL/glut.h>
#include "draw.h"
#include "const.h"


void renderBitmapString(float x, float y, void *font, char *str);

void showSignature();

void draw_net(void);

void drawCircle(float x, float y, float r, int amountSegments);





#endif // DRAW_H_INCLUDED
