#include <GL/glut.h>
#include <cmath>    //sqrt, pow
#include <iostream> //io
#include <cstdlib> //itoa
#include "checker.h"
#include "const.h"
#include "draw.h"
#include "king.h" // for CHECKER -> KING
using namespace std;

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

    //debug index
    char *string = new char[10];
    itoa(this->getIndex(), string, 10);
    glColor3f(1, 1, 1);
    renderBitmapString(x0, y0, GLUT_BITMAP_9_BY_15, string);
    delete[]string;
}

//return index [1...N] > 0
//otherwise 0
int Checker::isBusyPlace(int x, int y){
    for (int i = 0; i < this->getCount(); i ++){ //test for unique location
        if (check[i]->getIndex() > 0) //alive
        if (check[i]->get_x() == x &&
            check[i]->get_y() == y   )
            return check[i]->getIndex();
    }
    return 0; //it's empty place
}

void Checker::move(int dx, int dy){

    cout << "CHECKER" << endl;
    cout << "dx = " << dx << endl;
    cout << "dy = " << dy << endl;

    if ( isBusyPlace(this->get_x() + dx, this->get_y() + dy ) )
        return;

    if ( abs(dx) != abs(dy) ) //step into the White Square
        return;

    if(this->getIndex() > this->getCount()/2){ //Player1 in the BOTTOM
        ///left up                 ///right up
        if ( (dx == -1  && dy == -1) || (dx == 1 && dy == -1)) {
            y += dy;
            x += dx;
            cout << "MOVE" << endl;
        if (this->get_y() == 0)
            check[this->getIndex()-1] = (*this)++;
        }
    }
    else{
        ///left down             ///right down
        if ( (dx == -1 && dy == 1) || (dx == 1 && dy == 1)){
            y += dy;
            x += dx;
            cout << "MOVE" << endl;
            if (this->get_y() == N-1)
                check[this->getIndex()-1] = (*this)++;
        }
    }

    ///Hit at any direction
    if ( abs(dx) == 2  && abs(dy) == 2 ){
        if (this->Hit(dx, dy) == 1){
            y += dy;
            x += dx;
            ///transform to the KING
            if ((this->getIndex() >  this->getCount()/2 && this->get_y() == 0) ||// Bottom Player go Up){
                (this->getIndex() <= this->getCount()/2 && this->get_y() == N-1) )// Upper Player go Down
                check[this->getIndex()-1] = (*this)++;
        }
    }
}

//return 1 if it is enemy
//otherwise 0
int Checker::isEnemy(int enemyIn){
    int enemyGroup = -1;
    int myGroup = -1;

    if( this->getIndex() <= this->getCount()/2 )
        myGroup = 1;
    if( enemyIn <= this->getCount()/2 )
        enemyGroup = 1;

    bool result = (myGroup != enemyGroup);
    cout << (result ? "ENEMY" : "ALLY") << endl;
    return result;
}

int Checker::Hit(int dx, int dy){
    //cout << "HIT" << endl;
    int checkExist = isBusyPlace(this->get_x() + dx/2, this->get_y() + dy/2 );
    if (!checkExist)
        return -1;
    if ( this->isEnemy(checkExist) ){ //can't beat our ally
        cout <<"checkExist = " << checkExist << endl;
        if ( check[checkExist-1]->getIndex() > 0){ //alive
            (*check[checkExist-1])--; // -1 = index and iterator difference
            return 1; //has beaten
        }
    }
    return -1; //can't beat
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
    cout << "HIT!" << endl;
}
