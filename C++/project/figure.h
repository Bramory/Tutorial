#ifndef _FIGURE_H_
#define _FIGURE_H_

class Figure{
        //static int count;
	public:
		Figure (int x_, int y_, char* aColor); // constructor
		Figure (const Figure &);				// copy constr
		Figure ();								// default
		virtual ~Figure();								// destructor

		int get_x() const; // print horizontal coordinate
		int get_y() const; // print  vertical  coordinate
		void set_x(int);
		void set_y(int);

		char* getColor() const;  // print chosen color
		void  setColor(char*);

		virtual void move(char direct); // change figure's location
		void draw()const; // draw on the board

	protected:
		char x;
		int  y;
		char* color;
};



#endif // _FIGURE_H_
