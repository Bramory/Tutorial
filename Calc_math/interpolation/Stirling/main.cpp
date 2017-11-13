#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "calc.h"
#include "const.h"
#include "draw.h"
using namespace std;

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
        glVertex2f(x*SCL, log(x)*SCL); //library function
    glEnd();
    glColor3f(0, 0, 0); // Our Point
    drawCircle(X*SCL, Y*SCL, 4, 20);
    glutSwapBuffers();
}

int main(int argc, char **argv){
    system("color 78"); //good print
    cout << "Enter the X(>0):" << endl;
    cin >> X; //5.2
    Y = Stirling(X);
    //Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_pos, y_pos);
    glutCreateWindow("Stirling's formula");
    //Registration
    glutDisplayFunc(display);
    Initialize();
    glutMainLoop();
    return 0;
}
