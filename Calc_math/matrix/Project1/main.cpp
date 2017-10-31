//#include "stdafx.h"
#include <iostream>
#include "matrix.h"
using namespace std;

int main(void) {
	cout << "Enter matrix size, please" << endl;
	cin >> x;
	cin >> y;
	matrix MyMatr(x, y);
	cout << "Enter " << x*y <<" numbers:" << endl;
	MyMatr.read();
	MyMatr.print();


return 0;
}