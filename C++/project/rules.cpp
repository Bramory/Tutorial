#include "rules.h"

int teamCount(int team)
{
    int amount = 0, b_in, f_in;
    if (team == RED_TEAM){
        b_in = 0;
        f_in = 12;
    }
    else if (team == BLUE_TEAM){
        b_in = 12;
        f_in = 24;
    }

    for(int i = b_in; i < f_in; i++)
        if(check[i]->getIndex() > 0 )
            amount++;

    return amount;
}

void Winner (int team){
    int aSize = 10;
    char *str = new char[aSize];

    if (team == RED_TEAM){
        glColor3f(1,0,0);
        str = "RED WINS";

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0, 0);
            glVertex2f(width, 0);
            glColor3f(0,0,1);
            glVertex2f(width, height);
            glColor3f(1,0,0);
            glVertex2f(0, height);
        glEnd();

        glColor3f(0,0,1);
    }
    else if (team == BLUE_TEAM){

        str = "BLUE WINS";
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(1,0,0);
            glVertex2f(0, 0);
            glColor3f(0,0,1);
            glVertex2f(width, 0);
            glVertex2f(width, height);
            glVertex2f(0, height);
        glEnd();

        glColor3f(1,0,0); //for str lable
    }
    renderBitmapString(width/2 - 30, height/2, GLUT_BITMAP_TIMES_ROMAN_24, str);
    delete[]str;
}

// our choice is similar for mandatory
// or list is empty                  -> return  (1)
// list exist and myIn != (index from list)->  (-1)
int checkMandatoryTaking(int myIndex){
    int moveExist = 0, b_in, f_in;

    if (priority == RED_TEAM){
        b_in = 0;
        f_in = 12;
    }
    else if (priority == BLUE_TEAM){
        b_in = 12;
        f_in = 24;
    }

    for(int i = b_in; i < f_in; i++){
        if(check[i]->getIndex() > 0 && check[i]->possibleMoves() == 1 ){
            moveExist = 1;
            if ( check[i]->getIndex() == myIndex )
                return 1;
        }
    }

    if(moveExist)
        return -1; /// there is mandatory move
    else
        return 1; ///list is empty, move it's up to you
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
