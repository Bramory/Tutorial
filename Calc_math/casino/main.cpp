#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "calc.h"
#include "const.h"
#include "draw.h"
using namespace std;

int cash = 1000;
int stack = 1;

void Initialize (){
    glClearColor(1, 1, 1, 1.0);
    glOrtho(0, width, 0, height, -1, 1);
}


void Casino (void) {
    int win = rand() % 2;
    if(win){
        cash += stack;
        stack = 1;
    }
    else
    {
        if(cash == stack)
            cout << "MAX: " << cash << endl;

            cash -= stack;
            stack *= 2;
        if (stack > cash)
            stack = cash;
    }
}

void display(){
    system("cls");
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);

    glPointSize(1);
    glBegin(GL_POINTS);
        glColor3f(0, 0, 1);
        int i = 0;
        while(cash>0){
            glVertex2f(i/SCL, cash/SCL);
            Casino();
            i++;
        }
    glEnd();
    cout << "Tries: " << i << endl;
    cout << "Cash: " << cash << endl;
    glutSwapBuffers();
    cash = 1000;
}

int main(int argc, char **argv){
    srand(time(0));
    system("color 78"); //good print


    //Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_pos, y_pos);
    glutCreateWindow("Casino");
    //Registration
    glutDisplayFunc(display);
    Initialize();
    glutMainLoop();
    return 0;
}
