#include <GL/glut.h>
#include <cmath>
#include <cstring>
#include "draw.h"
#include "calc.h"
#include "const.h"

void Initialize (){
    glClearColor(1, 1, 1, 1.0);
    glOrtho(-width/2, width/2, -height/2, height/2, -1, 1);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    draw_net();      // Cartesian
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP); // Graph
    for(float x = -width; x < width; x += 0.1)
        glVertex2f(x*SCL, formula(y_size, coeff, x)*SCL); //library function
    glEnd();
    glColor3f(0, 0, 0); // Our Point
    for(int i = 0; i < N; i ++)
        drawCircle(x_t[i]*SCL, y[i]*SCL, 4, 20);
    glutSwapBuffers();
}

void renderBitmapString(float x_, float y_, void *font, char *str){
  char *c;
  int aLength = strlen(str);
  int i;
  for (i = 0; i < aLength; i++)
        x_ -= 4; //bias for words
  glRasterPos2f(x_, y_); //there
  for (c = str; *c != '\0'; c++) // draw string
        glutBitmapCharacter(font, *c);
}

void showSignature(){
    int  bias = 17;
    renderBitmapString(-bias/2        , -bias         , GLUT_BITMAP_8_BY_13, "0" );
    renderBitmapString(width/2 - bias , -bias         , GLUT_BITMAP_8_BY_13, "X" );
    renderBitmapString(-bias          , height/2-bias , GLUT_BITMAP_8_BY_13, "Y" );
}

void draw_net(void){
    showSignature(); //draw "aValue" , "Y", "0"
    int bias = 12; //for coordinate arrows
    glBegin(GL_LINES);
    glVertex2f(-width, 0); //axis "aValue"
    glVertex2f(width, 0);

    glVertex2f(0, -height); //axis "Y"
    glVertex2f(0, height);
    glEnd();

    int dist = 30;
    glBegin(GL_LINES); // draw lines on the axes
    for (int i = -(width/dist) * dist; i < width/2 * 0.9; i += dist ){ //axis "aValue"
        glVertex2f(i, dist/4);
        glVertex2f(i, -dist/4);
    }
    for (int i = -(height/dist) * dist; i < height/2 * 0.9; i += dist ){ //axis "Y"
        glVertex2f(dist/4, i);
        glVertex2f(-dist/4, i);
    }
    glEnd();

    glBegin(GL_LINE_STRIP); // arrow for "Y"
    glVertex2f(-bias/2, height/2 - bias);
    glVertex2f(0 , height/2);
    glVertex2f(bias/2, height/2 - bias);
    glEnd();

    glBegin(GL_LINE_STRIP); // arrow for "aValue"
    glVertex2f(width/2 - bias, bias/2);
    glVertex2f(width/2, 0);
    glVertex2f(width/2 - bias, -bias/2);
    glEnd();
}

void drawCircle(float x, float y, float r, int amountSegments){
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < amountSegments; i++){
        float angle = 2.0 * 3.1415926 * (float)(i) / (float)amountSegments;
        float dx = r * cosf(angle);
        float dy = r * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}
