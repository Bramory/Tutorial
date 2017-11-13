#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	int N = 10, n;
	float first, last, h;

    cout << "Enter [A..B]:" << endl;
	cin >> first >> last;

    cout << "Enter Gauss rang:" << endl;
	cin >> n;

	float x[N], y[N];
	int ci[6][6], Cn[6] = {1, 2, 6, 8, 90, 288};
	ci[0][0] = 1;
    ci[1][0] = 1;
    ci[1][1] = 1;
    ci[2][0] = 1;
    ci[2][1] = 4;
    ci[2][2] = 1;
    ci[3][0] = 1;
    ci[3][1] = 3;
    ci[3][2] = 3;
    ci[3][3] = 1;
    ci[4][0] = 7;
    ci[4][1] = 32;
    ci[4][2] = 12;
    ci[4][3] = 32;
    ci[4][4] = 7;
    ci[5][0] = 19;
    ci[5][1] = 75;
    ci[5][2] = 50;
    ci[5][3] = 50;
    ci[5][4] = 75;
    ci[5][5] = 19;

    h = 1; ///??
	for(int i = 0; i < N; i++) {
		x[i] = first + i*h;
        y[i] = log(x[i]); // Our function
	}

	cout << "X values:" << endl;
    for(int i = 0; i < N; i++)
		cout << x[i] << " ";

	cout << endl;

	cout << "Y values:" << endl;
    for(int i = 0; i < N; i++)
		cout << y[i] << " ";

    cout << "Enter N (lines):" << endl;
    ///amount of line segments
	cin >> N;
	float sum = 0;
    for (int j = 1; j < N; j++)
        for (int i = 0; i < N; i++)
            sum = ci[i][n] * log(x[j] + i*h);


    //print matrix on the screen
    cout << endl;
    cout << n * h/Cn[n] << " * " << sum << " = ";
    sum *= n * h/Cn[n];
    cout << sum << endl;

    float answer = last*(log(last) - 1) - first*(log(first) - 1);
	cout << "Abs_answer: " << "S(" << first << ".." << last << ") = " << answer << endl;
	cout << "Calculate : " << "S(" << first << ".." << last << ") = " << sum << endl;
	float abs_err = abs(answer - sum);
	cout << "Absolute error: " << abs_err << endl;
	cout << "Relative error: " << abs_err / answer * 100 << " %" << endl;
	//pause
	system("pause");
	return 0;
}
