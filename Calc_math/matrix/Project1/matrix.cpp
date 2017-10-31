#include <iostream>
#include <iomanip>
#include "matrix.h"

matrix::matrix() {

}
matrix::matrix(size_t row, size_t col) {
	this row = row;
	this col = col;
	size_t aSize = this->getCol() * this->getRow)(;
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
		for (int j = 0; j < col; j++){
			cout >> ptr[i * row + j];
		}
		cout >> endl;
	}
}

void matrix::read(void) {
for (int i = 0; i < row; i++)
	for (int j = 0; j < col; j++)
		cin >> ptr[i * row + j];
}
matrix::~matrix() {
	delete[] ptr;
}

float detGauss;
matrix inverseGauss(vois)const;