#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "figure.h"
#include "checker.h"
#include "king.h"
#include "keyboard.h"
#include "const.h"
#include "draw.h"
#include "mouse.h"
#include "rules.h"
using namespace std;

int Checker::amount;
//window position
int N = 8;
int x_position = 950;
int y_position = 0;
int width  = 400; //glutGet(GLUT_SCREEN_WIDTH);
int height = 400; //glutGet(GLUT_SCREEN_HEIGHT) * 0.91;

int x = 0;
int y = 0;
float CELL_WIDTH  = width /N;
float CELL_HEIGHT = height/N;
float checkRadius = CELL_WIDTH*2/5; //radius
int activeCheck = -1;
int priority = -1;

int sleep = 30;
Checker *check[24];

const int RED_TEAM = 1;
const int BLUE_TEAM = -1;

void Initialize (){
    glClearColor(1, 1, 1, 1);
    glOrtho(0, width, height, 0, -1, 1);
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    int r = teamCount(RED_TEAM);
    int b = teamCount(BLUE_TEAM);

    if(r > 0 && b > 0){
        drawBoard();
        drawCheckers();
    }

    if(r == 0)
        Winner(BLUE_TEAM);

    if (b == 0)
        Winner(RED_TEAM);

    glutSwapBuffers();
}

void MyIdle(){
    glutPostRedisplay();
    Sleep(sleep);
    //glutSetWindowTitle("");
}

 void timer(int a){
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
 }


int main(int argc, char **argv){

    srand(time(0));
    initCheck();

    //debug
//    for(int i = 0; i < check[0]->getCount(); i ++){
//        cout << " i = " << i << endl;
//        cout << *(check[i]);
//    }

    cout << "countCHECK = " << check[0]->getCount() << endl;
    //Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_position, y_position);
    glutCreateWindow("Checkers");

    //Registration
    Initialize();
    glutDisplayFunc(display);
    glutTimerFunc(500, timer, 0);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SKeyboard);
//    glutPassiveMotionFunc(MouseMove);
//    glutMotionFunc(MousePressedMove);
    glutMouseFunc(MousePressed);
    glutIdleFunc(MyIdle);
    glutMainLoop();

    return 0;
}
