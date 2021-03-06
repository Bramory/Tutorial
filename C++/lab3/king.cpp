#include <GL/glut.h>
#include <iostream> //io
#include <cstdlib> //itoa
#include <cmath> //itoa

#include "checker.h"
#include "const.h"
#include "draw.h"
#include "king.h"
using namespace std;

//Transform Checker -> King
King *Checker::operator ++ (int){
    King *ptr = new King(x, y, color);
    ptr->setIndex( this->getIndex() );
    cout << "Index King'a = " << ptr->getIndex() << endl;
    amount--; //transform not increase amount
    return ptr;
}

void King::draw(void){
    int x0 = x * CELL_WIDTH  + CELL_WIDTH/2; // center of the cell
    int y0 = y * CELL_HEIGHT + CELL_HEIGHT/2;

    //glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    chooseColor(this);
    glVertex2f(x0-15, y0-10);
    chooseColor(this);
    glVertex2f(x0, y0-20);
    glColor3f(0,1,0);
    glVertex2f(x0+15, y0-10);
    glColor3f(0.5,0,0.5);
    glVertex2f(x0+10, y0+10);
    glColor3f(0,1,0);
    glVertex2f(x0-10, y0+10);
    glEnd();

    //debug
    char *string = new char[10];
    itoa (this->getIndex(), string);
    glColor3f(1, 1, 1);
    renderBitmapString(x0, y0, GLUT_BITMAP_9_BY_15, string);
    delete[]string;
}

int King::Hit(int dx, int dy){
    cout << "King" << endl;
    int inFigure = isBusyPlace(this->get_x() + dx/2, this->get_y() + dy/2 );
    if ( this->isEnemy(inFigure) ){ //can't beat our ally
        cout <<"inFigure = " << inFigure << endl;
        if (inFigure != 0)
            if ( check[inFigure-1]->getIndex() > 0){ //alive
                (*check[inFigure-1])--; // -1 = index and iterator difference
                return 1; //has beaten
            }
    }
    return -1; //can't beat
}

int King::move(int dx, int dy){
    cout << "KING" << endl;

//    dx = round(dx);
//    dy = round(dy);
    cout << "dx = " << dx << endl;
    cout << "dy = " << dy << endl;

    if ( isBusyPlace(this->get_x() + dx, this->get_y() + dy ) )
        return 0;

    if ( abs(dx) != abs(dy) ) //step into the White Square
        return 0;

    if ( abs(dx) == 1){
        y += dy;
        x += dx;
        cout << "KING MOVE " << endl;
    }
    else{
        int busyPlaces = 0;
        int inFigure = 0;
        int inFigureTest;
        for(int i = 1; i < abs(dx); i++){ //last place already check
                int step_x = i * copysign(1, dx);
                int step_y = i * copysign(1, dy);
                cout << "step_x = " << step_x << endl;
                cout << "step_y = " << step_y << endl;
            if ( inFigureTest = isBusyPlace(this->get_x() + step_x, this->get_y() + step_y) ){
                inFigure = inFigureTest;
                busyPlaces++;
                // too many figures between start and finish places
                if (busyPlaces > 1)
                    return 0;
                // can't kill allies
                if ( !this->isEnemy(inFigure) ){
                    cout << "inFigure " << inFigure << endl;
                    return 0;
                }
            }
        }
        if (inFigure > 0) ///we find 1 enemy and will destroy him ...
            if ( check[inFigure-1]->getIndex() > 0){ //alive
                (*check[inFigure-1])--;
//                cout << "KING HIIIITTT " << endl;
                y += dy;
                x += dx;
                return 2;
            }
            //...or just change coordinates
        y += dy;
        x += dx;
    }
    return 1;
}

///legal moves exist return 1
///no moves for hitting opponent -1
int King::possibleMoves(void){
        // left'n'up
        cout << "myPosition: " << this->get_x() << " " << this->get_y() << endl;

        if( (((this->get_x()-2) >= 0) && ((this->get_y()-2) >= 0))  &&
            !isBusyPlace(this->get_x()-2, this->get_y()-2) &&
            isEnemy(isBusyPlace(this->get_x()-1, this->get_y()-1)) == 1 ){
//            cout << "Not Busy: " << this->get_x()-2 << " " << this->get_y()-2 << endl;
//            cout << "there is Enemy: " << this->get_x()-1 << " " << this->get_y()-1 << endl;
            return 1;
        }
        if( (((this->get_x()+2) < N) && ((this->get_y()-2) >= 0)) &&
            !isBusyPlace(this->get_x()+2, this->get_y()-2) &&
            isEnemy(isBusyPlace(this->get_x()+1, this->get_y()-1)) == 1 ){
//            cout << "Not Busy: " << this->get_x()+2 << " " << this->get_y()-2 << endl;
//            cout << "there is Enemy: " << this->get_x()+1 << " " << this->get_y()-1 << endl;
            return 1;
        }
        if( (((this->get_x()+2) < N) && ((this->get_y()+2) < N)) &&
            !isBusyPlace(this->get_x()+2, this->get_y()+2) &&
            isEnemy(isBusyPlace(this->get_x()+1, this->get_y()+1)) == 1 ){
//            cout << "Not Busy: " << this->get_x()+2 << " " << this->get_y()+2 << endl;
//            cout << "there is Enemy: " << this->get_x()+1 << " " << this->get_y()+1 << endl;
            return 1;
        }
        if( (((this->get_x()-2) >= 0) && ((this->get_y()+2) < N)) && //exist cell in a board
            !isBusyPlace(this->get_x()-2, this->get_y()+2) &&       // there space after figure
            isEnemy(isBusyPlace(this->get_x()-1, this->get_y()+1)) == 1 ){ //enemy near activeChecker
//            cout << "Not Busy: " << this->get_x()-2 << " " << this->get_y()+2 << endl;
//            cout << "there is Enemy: " << this->get_x()-1 << " " << this->get_y()+1 << endl;
            return 1;
        }
 return -1;
}


King::~King(){
    //dtor
}
