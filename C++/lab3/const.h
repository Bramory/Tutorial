#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED
#include "checker.h"

//window position
extern int N;
extern int x_position;
extern int y_position;
extern int width;
extern int height;
extern float CELL_WIDTH;
extern float CELL_HEIGHT;

//for random filling
extern int MIN_VALUE;
extern int MAX_VALUE;

//for mouse coordinate
extern int x;
extern int y;

//for graphics
extern int sleep;
extern Checker *check[24];
extern float checkRadius;
extern int activeCheck;
extern int priority;


#endif // CONST_H_INCLUDED
