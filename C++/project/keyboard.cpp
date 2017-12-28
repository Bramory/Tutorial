#include <GL/glut.h>
#include <iostream>
#include "keyboard.h"
#include "checker.h"
#include "king.h"
#include "const.h"
using namespace std;

void Keyboard(unsigned char key, int x, int y){
    switch (key){
    case 'e':
        exit(0);
        break;
    }
}

void SKeyboard(int key, int x, int y){
    switch (key){

    case GLUT_KEY_LEFT:

        break;

    case GLUT_KEY_RIGHT:

        break;

    case GLUT_KEY_UP:
        //check[0] = (*check[0])++;//->operator ++(0); // ++
        break;

    case GLUT_KEY_DOWN:
        //check[23] = (*check[23])++;
        break;
    }
}
