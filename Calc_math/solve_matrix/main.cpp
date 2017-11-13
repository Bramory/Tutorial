#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matrix.h"
using namespace std;

int main(void) {
    srand(time(0));
    setlocale(LC_CTYPE, "rus");

    int x = 4, y = 3;
	cout << "Enter " << x*y <<" numbers:" << endl;
//	MyMatr.read();
//	MyMatr.print();

	matrix MyMatr(3, 4);
	MyMatr.solveSystem();

	//matrix inverse = MyMatr.inverseGauss();


// cout << "Inverse Matrix :" << endl;
// inverse.print();

return 0;
}
