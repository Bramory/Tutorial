#include <iostream>
using std::cout;
using std::endl;
#include <math.h>

int main(){
    double a = 3.485, b = 4.512;
    cout << "\nBefor rounding:" << endl;
    cout << "a = " << a << "\tb = " << b << endl;

    a = round(a * 100.0) / 100.0;
    b = round(b * 100.0) / 100.0;
    cout << "\nAfter rounding:" << endl;
    cout << "a = " << a << "\tb = " << b << endl;

    return 0;
}


// full + fractional parts
/*
    double ration_x, dx = 1.234;
    ration_x = modf(dx, &dx);

    cout << dx << endl;
    cout << ration_x << endl;

    dx += copysign(1, dx);
*/
