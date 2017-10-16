#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "figure.h"
#include "checker.h"
#include "king.h"
#include "keyboard.h"
#include "const.h"
#include "draw.h"
#include "mouse.h"
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
int priority = 1;

int sleep = 1000;
Checker *check[24];

void Initialize (){
    glClearColor(1, 1, 1, 1);
    glOrtho(0, width, height, 0, -1, 1);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawBoard();
    for (int i = 0; i < check[0]->getCount(); i++){ //
        if (check[i]->getIndex() > 0){ //alive //perevirka
            check[i]->draw();
        }
    }
    glutSwapBuffers();
}

void MyIdle(){
    glutPostRedisplay();
    Sleep(sleep);
}

 void timer(int a){
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
 }


 void initCheck(void){
    //Red Command
    int attrib0 = 0, attrib1 = 1;
    int it = 0;
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < N; x++){
            if ( ((y*N + x) & 1) == attrib1){ //even row => odd coordinate
                check[it++] = new Checker(x, y, "Red");
            }
            if ( x == N-1 && (N & 1) == 0 ) // the last square in a row have odd index (N == not even)
                swap(&attrib1, &attrib0); //odd row => even coordinate
        }
    }
    //Blue Command
    for (int y = N - 3; y < N; y++){
        for (int x = 0; x < N; x++){
            if ( ((y*N + x) & 1) == attrib1){ //even row => odd coordinate
                check[it++] = new Checker(x, y, "Blue");
            }
            if ( x == N-1 && (N & 1) == 0 ) // the last square in a row have odd index (N == not even)
            swap(&attrib1, &attrib0); //odd row => even coordinate
        }
    }
 }

int main(int argc, char **argv){

    initCheck();

    //debug
    for(int i = 0; i < check[0]->getCount(); i ++){
        cout << " i = " << i << endl;
        cout << *(check[i]);
    }

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
    glutMainLoop();

    return 0;
}
