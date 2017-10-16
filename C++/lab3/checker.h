#ifndef CHECKER_H
#define CHECKER_H

#include <iostream>
#include "figure.h"

class King;

class Checker : public Figure{
        static int amount;
    protected:
        int index;
    public:
        //constructors
        Checker(int x_, int y_, char* aColor) : Figure(x_, y_, aColor), index(++amount){}
        Checker(): Figure(), index(++amount){}
        Checker(const Checker& src);
        virtual ~Checker();

//        void setCount(int );
		int getCount()const;
		int getIndex()const;
		void setIndex(int);
        virtual void draw(void);
        virtual void move(int dx, int dy);
        virtual int Hit(int dx, int dy);
        int isEnemy(int enemyIn);
        int isBusyPlace(int x, int y);

        friend std::ostream & operator << (std::ostream &s, Checker &obj);
        friend std::istream & operator >> (std::istream &s, Checker &obj);
        King* operator ++ (int);
        Checker& operator = (const Checker& right);
        void operator -- (int);
};


#endif // CHECKER_H
