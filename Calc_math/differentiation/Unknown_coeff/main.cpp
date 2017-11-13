//метод неизвестных коэффициентов
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

float sigmaB(float xi, float x0, int n){
    return pow(xi - x0, n);
}
                                                    /// GAGAGA   GAUSSSSSSSSSS
float sigmaC(float X, float x0, int n){
    int res = 0;
    if (n != 0)
        return n * pow(X - x0, n-1);
    else
        return res;
}

int main() {
	int N = 5;
	int h = 1;
	float first = 2;

    cout << "Enter point X:" << endl;
    float x_pt = 5.2;
	cin >> x_pt;

    cout << "Enter step (h):" << endl;
	cin >> h;

	first = x_pt - h;

	float x0[N], y[N], a[N][N+1];
	//enter table of begin values: x, y
	for(int i = 0; i < N; i++) {
		x0[i] = first + i*h;
        y[i] = log(x0[i]); // Our function
	}

	cout << "X values:" << endl;
    for(int i = 0; i < N; i++)
		cout << x0[i] << " ";

	cout << endl;

	cout << "Y values:" << endl;
    for(int i = 0; i < N; i++)
		cout << y[i] << " ";

	///difference (h, 2h..) <==> (X-x0)^i
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			a[i][j] = sigmaB(x0[j], x0[0], i);
	}

	///right part of the matrix (derivative)
	for (int i = 0; i < N; i++)
        a[i][N] = sigmaC(x_pt, x0[0], i);

	///lets solve our system with Gauss method
	int n = N;
    float mult, x[n];
    //print matrix on the screen
    cout << endl << "Our Matrix: " << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++)
            cout << setw(3) << a[i][j] << " ";
        cout << endl;
    }

    float Y = (float)1/12 * h * (-3*y[0] - 10*y[1] + 18*y[2] -6*y[3] + y[4]);
	cout << "Abs_answer: " << "log" << "(" << x_pt << ") = " << 1/x_pt << endl;
	cout << "Calculate : " << "log" << "(" << x_pt << ") = " << Y << endl;
	double abs_err = abs(Y - 1/x_pt);
	cout << "Absolute error: " << abs_err << endl;
	cout << "Relative error: " << abs_err / (1/x_pt) * 100 << " %" << endl;
	//pause
	system("pause");
	return 0;
}
