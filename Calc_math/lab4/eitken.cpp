#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
	int N = 7, h = 1;
	float x = 5.2, first = 2;

	cout << "Enter your function: f(x) = :" << endl;
	char func[10];
	cin.getline(func, 10);
	float(*fx)(float);//pointer on function
	if (!strcmp("log", func))
		fx = log;
	else if (!strcmp("sin", func))
		fx = sin;
	else if (!strcmp("cos", func))
		fx = cos;
	else {
		cout << "Incorrect input!";
		system("pause");
		exit(-1);
	}

	cout << "Enter point X:" << endl;
	cin >> x;

	cout << "Enter amount of points (N):" << endl;
	cin >> N;
	cout << "Enter first X from table:" << endl;
	cin >> first;
	cout << "Enter step (h):" << endl;
	cin >> h;

	float matr[9][9];
	//init array, set values = 0
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matr[i][j] = 0;
		}
	}

	//enter table of begin values: x, y
	for(int i = 0; i < N; i++) {
		matr[i][0] = first + i*h;
		if ( !strcmp(func, "sin") || !strcmp(func, "cos") ||
			 !strcmp(func, "tan") )
			matr[i][1] = fx(matr[i][0] * 3.141592 / 180);  //grad => radian
		else
			matr[i][1] = fx(matr[i][0]); // Our function
	}

	//calculation
	cout << "Debug Table:" << endl;
	for (int i = 2, n = 0; i < N; i++, n++) {
		for (int j = 1 + n; j < N; j++) {
			matr[j][i] = 1/(matr[j][0] - matr[n][0]) *
						 ( matr[n][1+n] * (matr[j][0] - x) -
						   matr[j][1+n] * (matr[0+n][0] - x));
			cout << setprecision(5) << "y(" << j << "/" << i - 1 << ") = "; //i-1 'cause table with "x" values
			cout << setprecision(5) << "1/(" << matr[j][0] << "-" << matr[0 + n][0] << ") * [";
			cout << setprecision(5) << matr[0 + n][1 + n] << " * " << "(" << matr[j][0] << " - " << x << ") - ";
			cout << setprecision(5) << matr[j][1 + n] << " * " << "(" << matr[0 + n][0] << " - " << x << ")]";
			cout << " = " << matr[j][i] << endl;
		}
	}

	//print matrix on the screen
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setprecision(6) << setw(2) << matr[i][j] << setw(2) << " ";
		}
		cout << endl;
	}

	cout << "Abs_answer: " << func << "(" << x << ") = " << fx(x) << endl; //TO DO for trigonometry:  x * 3.141592 / 180
	cout << "Calculate : " << func << "(" << x << ") = " << matr[N-1][N-1] << endl;
	double abs_err = abs(matr[N - 1][N - 1] - fx(x));
	cout << "Absolute error: " << abs_err << endl;
	if (!strcmp(func, "sin") || !strcmp(func, "cos") || //???!!!
		!strcmp(func, "tan"))
		x *= 3.141592 / 180;
	cout << "Relative error: " << abs_err / fx(x) * 100 << " %" << endl;
	//pause
	cin >> N;
	return 0;
}
