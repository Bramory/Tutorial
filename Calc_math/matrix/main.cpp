///find inverse matrix by 2 methods: Gauss and algebraic complements.
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "matrix.h"
using namespace std;

int main(void) {
	int x, y;
	cout << "Enter matrix size, please {[x], [y]} > 0 " << endl;
		do {
			x = num_scan();
			y = num_scan();
			if (x > 0 && y > 0) break;
			cout << "Invalid size!" << endl;
		} while (1);

		matrix MyMatr(x, y);
		cout << "Matr.row: " << MyMatr.getRow() << endl;
		cout << "Matr.col: " << MyMatr.getCol() << endl;
		cout << "Enter " << x*y << " numbers" << endl;
		MyMatr.read();
        MyMatr.print();
		cout << "Matrix det: " << MyMatr.det() << endl;

		cout << "Matrix inverse: " << endl;
			matrix inverse = MyMatr.inverseGauss();
		inverse.print();

                        //		cout << "Matrix original: " << endl;
                        //		MyMatr.print();
//		cout << endl << endl << " A * A ^ (-1) = E " << endl;
//		matrix TestM = MyMatr * inverse;
//		TestM.print();
		system("pause");
		return 0;
}
