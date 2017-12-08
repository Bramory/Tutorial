#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double (*f)(double) = log;

double findRoot(double a, double b, double e){
	while (abs(f(b)) > e)	{
		a = b - ((b - a) * f(b)) / (f(b) - f(a)); // up to you
		b = a - ((a - b) * f(a)) / (f(a) - f(b));
	}
	return b;
}

int main(){
    double a, b, e;
    cin >> a >> b >> e;

    if (f(a)*f(b) > 0){
    cout << "incorrect input!\n";
    system("pause");
    return 0;
    }

    cout << findRoot(a, b, e);

    system("pause");
    return 0;
}
