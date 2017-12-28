#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "checker.h"

class King : public Checker{
    public:
        King(int x, int y, char* aColor): Checker(x, y, aColor){}
        King() : Checker(){}
        virtual ~King();
        King(const King& other);//:Checker(other){} //??
        virtual void draw(void);
        virtual int move(int dx, int dy);
        virtual int Hit(int dx, int dy);
        virtual int possibleMoves(void);

        King& operator =(const King& right);
};

#endif // KING_H_INCLUDED
