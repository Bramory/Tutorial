#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include "matrix.h"
using namespace std;


/*
    const int n = 3; //Размерность системы
    float a[n*n + n+1],a0[n*n + n+1];    //A - расширенная матрица системы, A0 - ее копия для проверки решения
    float mult,x[n],b[n];
    cout << "Матрица и вектор правой части";
    for (int i=0; i<n; i++) {
        cout << endl;
        for (int j=0; j<n+1; j++) {
            //a0[i][j]=a[i][j]=1+rand()%100; /// деление на ноль не будет
            cin >> a[i*n +j];
            a0[i*n +j]=a[i*n +j];
        }
    }

    for (int i=0; i<n; i++) {
        cout << endl;
        for (int j=0; j<n+1; j++) {
            cout << a[i*n +j] << " ";
        }
    }

    //Прямой ход метода Гаусса
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++) {
            mult=a[i*n +i]/a[j*n +i];
        for (int k=0;k<=n;k++)
            a[j*n +k]= a[j*n +k]*mult-a[i*n +k];
    }
    //Обратный ход метода Гаусса
    x[n-1] = a[(n-1)*n +n]/a[(n-1)*n +n-1];
    for (int i=n-2;i>=0;i--) {
        mult=0;
    for (int j=i+1;j<n;j++)
        mult+=a[i*n +j]*x[j];
        x[i]=(a[i*n +n]-mult)/a[i*n +i];
    }

    cout << endl << "Решение" << endl;
    for (int i=0; i<n; i++)
        cout << x[i] << " ";

    cout << endl << "Проверка" << endl;
    for (int i=0; i<n; i++) {
        b[i]=0;
        for (int j=0; j<n; j++) b[i]+=a0[i*n +j]*x[j];
        cout << b[i] << " ";
    }
}
*/

matrix matrix::solveSystem(void){
    int n = 3; //Размерность системы
    float a[n][n+1],a0[n][n+1];    //A - расширенная матрица системы, A0 - ее копия для проверки решения
    float mult,x[n],b[n];
    cout << "Матрица и вектор правой части";
    for (int i=0; i<n; i++) {
        cout << endl;
        for (int j=0; j<n+1; j++) {
            //a0[i][j]=a[i][j]=1+rand()%100; /// деление на ноль не будет
            cin >> a[i][j];
            a0[i][j]=a[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        cout << endl;
        for (int j=0; j<n+1; j++) {
            cout << a[i][j] << " ";
        }
    }

    //Прямой ход метода Гаусса
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++) {
            mult=a[i][i]/a[j][i];
        for (int k=0;k<=n;k++)
            a[j][k]= a[j][k]*mult-a[i][k];
    }
    //Обратный ход метода Гаусса
    x[n-1] = a[n-1][n]/a[n-1][n-1];
    for (int i=n-2;i>=0;i--) {
        mult=0;
    for (int j=i+1;j<n;j++)
        mult+=a[i][j]*x[j];

        x[i]=(a[i][n]-mult)/a[i][i];
    }

    cout << endl << "Решение" << endl;
    for (int i=0; i<n; i++)
        cout << x[i] << " ";

    cout << endl << "Проверка" << endl;
    for (int i=0; i<n; i++) {
        b[i]=0;
        for (int j=0; j<n; j++)
            b[i]+=a0[i][j]*x[j];
        cout << b[i] << " ";
    }
}

matrix::matrix() {

}
matrix::matrix(size_t row, size_t col) {
	this->row = row;
	this->col = col;
	size_t aSize = row * col;//this->getCol() * this->getRow();
	ptr = new float[aSize];

	for (int i = 0; i < aSize; i++)
		ptr[i] = 0;
}
matrix::matrix(const matrix &obj) {
	ptr = new float[row * col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			ptr[i * row + j] = obj.ptr[i*row + j];
}

void matrix::print(void) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			//cout >> this->ptr[i * row + j];
			printf("%.3f ", this->ptr[i * row + j]);
		printf("\n");
	}
}

void matrix::read(void) {
for (size_t i = 0; i < row; i++)
	for (size_t j = 0; j < col; j++)
		cin >> ptr[i * row + j];
}

matrix::~matrix() {
	delete[] ptr;
}

//float matrix::detGauss{
//
//}

matrix matrix::inverseGauss(void){
    matrix inverse(row, col);
    for (int i = 0; i < row; i ++)
        inverse.ptr[i*row + i] = 1;

    ///direct detour
    for (int i = 0; i < row; i ++){
       for (int j = i+1; j < col; j++){
            float mult = (float) this->ptr[j*row + i]/ this->ptr[i*row+i];
            for (int c = 0; c < row; c++){ /// substract line
                this->ptr[j*row + c] -= (float)mult * this->ptr[i*row + c]; /// make '0'
                inverse.ptr[j*row + c] -= (float)mult * inverse.ptr[i*row + c];
            }
        }
    }


    //inverse.print();
    ///bypass
    for (int i = row -1; i >= 0; i--){
        float mult = this->ptr[i*row + i];
        for (int c = 0; c < row; c++){
            this->ptr[i * row + c] /= (float) mult;
            inverse.ptr[i * row + c] /= (float) mult;
        }

        for (int j = i-1; j >= 0; j--){
            mult = (float) this->ptr[j*row + i]/ this->ptr[i*row+i];
             for (int c = 0; c < row; c++){ /// substract line
                this->ptr[j*row + c] -= mult * this->ptr[i*row + c]; /// make '0'
                inverse.ptr[j*row + c] -= mult * inverse.ptr[i*row + c];
             }
        }
    }
    return inverse;
}
