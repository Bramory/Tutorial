#include <GL/glut.h>
#include <cmath>    //sqrt, pow
#include <iostream> //io
#include <cstdlib> //itoa
#include <cstring> // strlen
#include "checker.h"
#include "const.h"
#include "draw.h"
#include "king.h" // for CHECKER -> KING
using namespace std;

void reverse(char* str, int aSize){
    if (aSize <= 0 )
        return;

    char c;
    for(int i = 0; i < (aSize/2); i ++){
        c = str [aSize-1 - i];
        str [aSize-1 - i] = str[i];
        str[i] = c;
    }
}

void itoa(int num, char* str){
    int sign;
    if ((sign = num) < 0)
        num = -num;
    int i = 0;
    while (num > 0) {
        str[i] = num % 10 + '0';
        num /= 10;
        i++;
    }
    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str, strlen(str) );
}

int Checker::getCount()const{
   return amount;
}

int Checker::getIndex()const{
   return index;
}

void Checker::setIndex(int num){
    this->index = num;
}


Checker::~Checker(){
    --amount;
    delete [] color;
	cout << "Checker has been deleted." << endl;
    //dtor
}

void Checker::draw(void){
    chooseColor(this);
    int x0 = x * CELL_WIDTH  + CELL_WIDTH/2;
    int y0 = y * CELL_HEIGHT + CELL_HEIGHT/2;
    drawCircle( x0, y0, checkRadius,  20);

    //*******************************************************************************************************
    //debug index
//    int aSize = 10;
//    char *string = new char[aSize];
//    itoa(this->getIndex(), string);
//    glColor3f(1, 1, 1);
//    renderBitmapString(x0, y0, GLUT_BITMAP_9_BY_15, string);
//    delete[]string;
}

//return index [1...24] > 0
//otherwise 0
int isBusyPlace(int x, int y){
    for (int i = 0; i < check[0]->getCount(); i ++){ //test for unique location
        if (check[i]->getIndex() > 0) //alive
        if (check[i]->get_x() == x &&
            check[i]->get_y() == y   )
            return check[i]->getIndex();
    }
    return 0; //it's empty place_itoa_s
}

//only MOVE return 1
//There HIT return 2
//wrong step       0
//smth impossible -1
int Checker::move(int dx, int dy){

//    cout << "CHECKER" << endl;
//    cout << "dx = " << dx << endl;
//    cout << "dy = " << dy << endl;

    if ( isBusyPlace(this->get_x() + dx, this->get_y() + dy ) )
        return 0;

    if ( abs(dx) != abs(dy) ) //step into the White Square
        return 0;

    if(this->getIndex() > this->getCount()/2){ //Player1 in the BOTTOM
        ///left up                 ///right up
        if ( (dx == -1  && dy == -1) || (dx == 1 && dy == -1)) {
            y += dy;
            x += dx;
//            cout << "MOVE" << endl;
        // bottom player reach "Top" - convert Checker -> King
        if (this->get_y() == 0)
            check[this->getIndex()-1] = (*this)++;
        return 1; //move is made
        }
    }
    else{ //Player2 in the TOP
        ///left down             ///right down
        if ( (dx == -1 && dy == 1) || (dx == 1 && dy == 1)){
            y += dy;
            x += dx;
//            cout << "MOVE" << endl;
            // upper player reach "Bottom" - convert Checker -> King
            if (this->get_y() == N-1)
                check[this->getIndex()-1] = (*this)++;
            return 1; //move is made
        }
    }

    ///Hit at any direction
    if ( abs(dx) == 2  && abs(dy) == 2 ){
        if (this->Hit(dx, dy) == 1){
            y += dy;
            x += dx;
            ///transform to the KING after hitting an enemy
            if ((this->getIndex() >  this->getCount()/2 && this->get_y() == 0) ||// Bottom Player go Up){
                (this->getIndex() <= this->getCount()/2 && this->get_y() == N-1) )// Upper Player go Down
                check[this->getIndex()-1] = (*this)++;
            return 2;
        }
    }
return -1;//tupi4ok
}

//return 1 if it's enemy
//it's ally = 0
//otherwise -1 (empty space)
int Checker::isEnemy(int enemyIn){
    if(enemyIn < 1 || enemyIn > 24)
        return -1;

    int enemyGroup = -1;
    int myGroup = -1;

    //we in the left part
    if( this->getIndex() <= 24/2 )
        myGroup = 1;
    //enemyIn in the left part too
    if( enemyIn <= 24/2 )
        enemyGroup = 1;

    //  we in different parts?
    bool result = (myGroup != enemyGroup);
                // Yes ->    //No ->
//    cout << (result ? "ENEMY" : "ALLY") << endl;
    return result;
}

//hit is correct return 1
//can't beat     return -1
int Checker::Hit(int dx, int dy){
    //cout << "HIT" << endl;
    int checkExist = isBusyPlace(this->get_x() + dx/2, this->get_y() + dy/2 );
    if (!checkExist)
        return -1;
    if ( this->isEnemy(checkExist) ){ //can't beat our ally
        cout <<"checkExist = " << checkExist << endl;
        if ( check[checkExist-1]->getIndex() > 0){ //alive
            (*check[checkExist-1])--; // -1 'cause index and iterator difference
            return 1; //has beaten
        }
    }
    return -1; //can't beat
}

///legal moves exist return 1
///no moves for hitting opponent -1
int Checker::possibleMoves(void){
        // left'n'up
//        cout << "myPosition: " << this->get_x() << " " << this->get_y() << endl;

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

//operators
ostream& operator << (ostream &s, Checker &obj){
    cout << "X = " << obj.get_x() << endl;
    cout << "Y = " << obj.get_y() << endl;
    cout << "Color = " << obj.getColor() << endl;
    cout << "Index = " << obj.getIndex() << endl;
    cout << "Count = " << obj.getCount() << endl << endl;
    return s;
}

istream& operator >> (istream &s, Checker &obj){
    int x_, y_ ;
    char* color_ = new char[10];// = new char[10];   ????
    cout << "Please, set parameters for checker:" << endl;
    cout << "X = ";
    cin >> x_;
    obj.set_x(x_);

    cout << "Y = ";
    cin >> y_;
    obj.set_y(y_);

    cout << "Color = ";
    cin >> color_;
    obj.setColor(color_);

    cout << "END!"<< endl;
    return s;
}


Checker& Checker::operator =(const Checker& right){
    //self-assignment test
    if (this == &right) {
        return *this;
    }
    x = right.get_x();
    y = right.get_y();
    this->setColor(right.getColor());
    index = right.getIndex();
    return *this;
}

void Checker::operator -- (int){
    this->setIndex(-1); //in global array mark dead-checker
//    cout << "HIT!" << endl;
}
