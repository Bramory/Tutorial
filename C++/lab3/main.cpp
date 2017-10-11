#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "figure.h"
#include "checker.h"
#include "keyboard.h"
#include "const.h"
#include "draw.h"
using namespace std;

//int Figure ::count;
int Checker::amount;

//window position
int N = 8;
int x_position = 950;
int y_position = 0;
int width;
int height;

//for mouse coordinate
int x = 0;
int y = 0;

int sleep = 10;
Checker *check[4];

void Initialize (){
    glClearColor(1, 1, 1, 1);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawBoard();
//    if (aCrown.getIndex() > 0)
//        aCrown.draw();
    glColor3f(0, 1, 0);
    for (int i = 0; i < check[0]->getCount(); i++){ //?????????????????
        if (check[i]->getIndex() > 0){ //alive
            check[i]->draw();
//            cout << check[i];
//            system("pause");
        }
    }
    glutSwapBuffers();
}

void MyIdle(){
//    glutPostRedisplay();
    //Sleep(sleep);
}

 void timer(int a){
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
 }

int main(int argc, char **argv){

    check[0] = new Checker(0, 7, "Red");
//    check[0]->set_x(0);
//    check[0].set_y(7);
//    check[0].setColor();

    check[1] = new Checker(2, 5, "Blue");
//    check[1].set_x(2);
//    check[1].set_y(5);
//    check[1].setColor("Blue");

    check[2] = new Checker(3, 2, "Blue");
//    check[2] = check[1];
//    check[2].set_x(3);
//    check[2].set_y(2);

    King aCrown(1, 4, "White");

    //cin >> aCrown; // 6 1
    cout << "\n\n\nNewKing: \n" << aCrown << "\n" << endl;
    check[3] = &aCrown;
    check[0] = check[0]++;//->operator ++(1);

    //debug
    for(int i = 0; i < 4; i ++){
        cout << " i = " << i;
        cout << *(check[i]);
    }

//    cout << "countFIGURE = " << A.getCount() << endl;
//    cout << "countCHECK = " << check[0].getCount() << endl;
    //Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    width  = 400;//glutGet(GLUT_SCREEN_WIDTH);
    height = 400;//glutGet(GLUT_SCREEN_HEIGHT) * 0.91;
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_position, y_position);
    glutCreateWindow("Checkers");

    //Registration
    Initialize();
    glutDisplayFunc(display);
    glutTimerFunc(500, timer, 0);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SKeyboard);
    glutMainLoop();

    return 0;
}
