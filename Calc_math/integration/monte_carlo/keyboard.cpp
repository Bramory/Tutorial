#include <cstdlib>
#include <GL/glut.h>
#include "keyboard.h"
#include "const.h"

void SKeyboard(int key, int x, int y){
    system("cls");

    switch (key){
        case GLUT_KEY_LEFT:
        SCL --;
            break;

        case GLUT_KEY_RIGHT:
        SCL ++;
            break;

        case GLUT_KEY_UP:

            break;

        case GLUT_KEY_DOWN:

            break;
    }
}
