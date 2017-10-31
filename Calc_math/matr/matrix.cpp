#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "matrix.h"
using namespace std;

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
