#include <cmath>
#include <iostream>
#include <stdio.h>
#include "calc.h"
#include "const.h"
using namespace std;

long long int fact(int a){
	long long int r = 1;
	for (int i = 1; i <= a; i++)
        r *= i;
	return r;
}

float** init(int aSize){
	float** res;
	res = new float*[aSize];
	for (int i = 0; i<aSize; i++){
		res[i] = new float[aSize - i];
	}
	return res;
}

float** T(float** a, int aSize){
	float** res;
	res = init(aSize);
	for (int i = 0; i<aSize; i++){
		for (int j = 0; j<aSize - i; j++){
			res[i][j] = a[j][i];
		}
	}
	return res;
}

void showDiffTable(float first, float h, float** a, int aSize){
	for (int i = 0; i<aSize; i++){
		printf("%3.2f\t", first + h*i);   //X
		for (int j = 0; j<aSize - i; j++){
			printf("%3.2f\t", a[i][j]);   //Y
		}
		cout << "\n";
	}
}

float** getDiffTable(float *a, int aSize){
	float** res;
	res = init(aSize);
	res[0] = a;
	for (int i = 1; i<aSize; i++){
		for (int j = 0; j<=aSize - i; j++){
			res[i][j] = res[i - 1][j + 1] - res[i - 1][j]; //table of difference
		}
	}
	return T(res, aSize);
}

inline float q(float x, float x0, float h){ return (x - x0) / h; }

float Q(float x, float x0, float h, int n){
	float res = q(x, x0, h);
	for (int i = 1; i<n; i++){
		res = res*(q(x, x0, h)*q(x, x0, h) - i*i);
	}
	return res;
}

float Stirling(float x){
    int N = 7; //amount of values
    float **Y;
    float Y_val[N];
    float F = 2; // first value in our table;
    float h = 1; //step

    //enter the table
    for (int i = 0; i < N; i++){
        Y_val[i] = log(F + i * h); // Y = table values
    }

    Y = getDiffTable(Y_val, N);
    showDiffTable(F, h, Y, N);

    int mid = ceil((float)(N / 2)); //central index
    float x0 = F + h*mid;
	float P = Y[mid][0]; //Zero part from table
	float temp1, temp2, temp3;
	for (int n = 1; n <= mid; n++){
		temp1 = Q(x, x0, h, n) / fact(2 * n - 1); //q(q^2 - i^2)/2n!/ (2n-1)!
		temp2 = (Y[-n + mid][2 * n - 1] + Y[-(n - 1) + mid][2 * n - 1]) / 2; //average difference
		temp3 = (Q(x, x0, h, n)*q(x, x0, h)) / fact(2 * n); // q^2(q^2 - i^2)/2n!
		P += (temp1)*(temp2)+(temp3)*(Y[-n + mid][2 * n]); //add parts
		//cout << (temp1)*(temp2) << "\n";
		//cout << (temp3)*(Y[-n + mid][2 * n]) << "\n";
	}
	float ln_val = log(x);
	cout << "q:  " << q(x, x0, h) << "\n";
	//cout << "x0:  " << x0 << "\n";
	cout << "Calculate_value:  " << P << "\n";
	cout << "Log(x)         :  " << ln_val << "\n";
	cout << "Absolute error :  " << abs(P - ln_val) << "\n";
    cout << "Relative error :  " << ((ln_val == 0) ? 0 : (abs(P - ln_val) / ln_val * 100)) << "%\n";

    float result = P;
    return result;
}
