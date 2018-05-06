// Lagrange.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

int main(void) {
	///default values
	int N = 7;
	float x = 3.5, h = 1, first = 1;

	///*****************bullshit*************************************

	cout << "Enter amount of points (N):" << endl;
	cin >> N;

	///init array, set values = 0

	int n = 3; // 1-st - X, 2-nd - Y, 3-rd - lagrange_coefficient
	vector < vector <float> > matr(n, vector <float>(N, 0));

	bool have_step = 0, have_func = 0;
	cout << "You have math_func? (yes-1/no-0)" << endl;
	cin >> have_func;

	cout << "Your table have step? (yes-1/no-0)" << endl;
	cin >> have_step;
	if (have_step) {
		cout << "Enter first value X:" << endl;
		cin >> first;
		cout << "Enter step:" << endl;
		cin >> h;
	}
	else
		cout << "Enter " << N << " X from the table:" << endl;

	if (!have_func && !have_step)
		cout << "Write like x1-y1, x2-y2..." << endl;
	else
		if (!have_func) {
			cout << "Enter " << N << " Y from the table:" << endl;
		}

	for (int j = 0; j < N; j++) {
		if (have_step)
			matr[0][j] = first + j * h;
		else
			cin >> matr[0][j];

		if (have_func)
			matr[1][j] = log(matr[0][j]); /// Our MATH_function's values
		else
			cin >> matr[1][j]; /// Our TABLE_function's values
	}
	///*****************bullshit*************************************


	///print matrix on the screen
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < N; j++) {
			cout << setprecision(3) << matr[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Enter point X:" << endl;
	cin >> x;

	///calculation
	float sum = 0;
	for (int j = 0; j < N; j++) {

		float denom = 1, numer = 1; //reset values
		for (int m = 0; m < N; m++) {
			numer *= (j != m ? (x - matr[0][m]) : 1);
		}
		for (int n = 0; n < N; n++) {
			denom *= (j != n ? (matr[0][j] - matr[0][n]) : 1);
		}

		matr[2][j] = matr[1][j] * (float)(numer / denom); //lagrange
		sum += matr[2][j];
	}

	///print matrix on the screen
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < N; j++) {
			cout << setprecision(3) << matr[i][j] << " ";
		}
		cout << endl;
	}

	//	cout << "Abs_answer: " << "log" << "(" << x << ") = " << setprecision(6) << log(x) << endl;
	cout << "Calculate : " << "function" << "(" << x << ") = " << setprecision(6) << sum << endl;
	//	double abs_err = abs(sum - log(x));
	//	cout << "Absolute error: " << abs_err << endl;
	//	cout << "Relative error: " << abs_err / log(x) * 100 << " %" << endl;

	//pause
	cin >> N;
	return 0;
}
