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
        void Hit(char);

        friend std::ostream & operator << (std::ostream &s, Checker &obj);
        friend std::istream & operator >> (std::istream &s, Checker &obj);
        King* operator ++ (int);
        Checker& operator = (const Checker& right);
        Checker  operator / (Checker const &rhs);
};

class King : public Checker{
    public:
        King(char x, int y, char* aColor): Checker(x, y, aColor){}
        King() : Checker(){}
        virtual ~King();
        King(const King& other);//:Checker(other){}
        void draw(void);

        King& operator =(const King& right);
//        friend std::ostream & operator << (std::ostream &s, King &obj);
//        friend std::istream & operator >> (std::istream &s, King &obj);
};


#endif // CHECKER_H
