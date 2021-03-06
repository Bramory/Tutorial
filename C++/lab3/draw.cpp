#include <GL/glut.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include "const.h"
#include "draw.h"
#include "checker.h"
using namespace std;

double const M_PI = 3.141592653589793238;


void renderBitmapString(float x, float y, void *font, char *string){
  char *c;
  int aLength = strlen(string);
  int i;
  for (i = 0; i < aLength; i++){ //align-center
        x -= 4; //for every char
  }
  glRasterPos2f(x, y);
  for (c = string; *c != '\0'; c++){
        glutBitmapCharacter(font, *c);
    }
}

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void drawBoard(void){
    int col1 = 1, col2 = 0;
    int x, y;
    for (y = 0; y < N; y++){
        for (x = 0; x < N; x++){
            if ( ((y*N + x) & 1) == 0)
                glColor3f(col1, col1, col1);
            else
                glColor3f(col2, col2, col2);

            if ( x == N-1 && (N & 1) == 0 )
                swap(&col1, &col2);
            glRecti(x    * CELL_WIDTH +1, y    * CELL_HEIGHT,
                   (x+1) * CELL_WIDTH,   (y+1) * CELL_HEIGHT);
        }
    }
}


void drawCircle(float x, float y, float r, int amountSegments){
    //int _r, _g, _b;
//    _r = rand() % 2;
//    _g = rand() % 2;
//    _b = rand() % 2;
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < amountSegments; i++){
//        _r = rand() % 2;
//        _g = rand() % 2;
//        _b = rand() % 2;
        float angle = 2.0 * M_PI * (float)(i) / (float)amountSegments;
        float dx = r * cosf(angle);
        float dy = r * sinf(angle);
        glVertex2f(x + dx, y + dy);
        glColor3f(0.1,0.1,0.1);
    }
    glEnd();
}

void chooseColor (Checker *Check){
    if (activeCheck == Check->getIndex() ){
        glColor3f(0, 1, 0);
        return;
    }
    char *aColor = Check->getColor();
    if (strcmp("White", aColor) == 0){
         glColor3f(1, 1, 1);
         return;
    }
    if (strcmp("Black", aColor) == 0){
        glColor3f(0.4, 0.4, 0.4);
        return;
    }
    if (strcmp("Red", aColor) == 0){
        glColor3f(1, 0, 0);
        return;
    }
    if (strcmp("Blue", aColor) == 0){
        glColor3f(0, 0, 1);
        return;
    }
    if (strcmp("Yellow", aColor) == 0){
    glColor3f(1, 1, 0);
    return;
    }
    else
        glColor3f(0, 1, 0);
}
