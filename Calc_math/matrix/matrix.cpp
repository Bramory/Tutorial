#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include "matrix.h"
using namespace std;

matrix::matrix() {
}

matrix::matrix(size_t row, size_t col) {
	this->row = row;
	this->col = col;
	size_t aSize = this->getCol() * this->getRow();
	ptr = new float[aSize];

	//init matrix with '0'
	for (int i = 0; i < aSize; i++)
		ptr[i] = 0;
}

// copy constructor
//matrix::matrix(const matrix& obj) {
//	float* newPtr = new float[row * col];
//	for (int i = 0; i < row; i++)
//		for (int j = 0; j < col; j++)
//			newPtr[i * row + j] = obj.ptr[i* row + j];
//}

matrix::~matrix() {
	delete[]ptr;
}

size_t matrix::getRow(void) const {
	return row;
}

size_t matrix::getCol(void) const {
	return col;
}
float matrix::det(void) const {
	//1. Non square matrix
	if (row != this->getCol()) {
		cout << "Matrix have wrong size!" << endl;
		exit(1); //??
	}

	//2. Matrix with 1 num
	if (row == 1)
		return this->ptr[0];

	//3. Simple matrix 2x2
	if (row == 2) {
		return this->ptr[0] * this->ptr[3] - this->ptr[1] * this->ptr[2];
	}

	//4. Matrix's dimension >= 3
	int index_line = 0, zero_amount = 0, zero_best = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (this->ptr[i*row + j] == 0)
				zero_amount++;
		}
		if (zero_amount > zero_best) {
			zero_best = zero_amount;
			index_line = i;
		}
		zero_amount = 0;
	}

	int det = 0, M_Size = this->row - 1;
	matrix local_matr(M_Size, M_Size);
	int a = index_line, b = 0; // a,b for number
	for (int n = 0; n < row; n++) { //searching
        int q = 0, w = 0; //reset for local_matr
		for (int i = 0; i < col; i++) {//minor
            for (int j = 0; j < col; j++){
			if (i != a && j != b) {
				local_matr.ptr[q*M_Size + w++] = this->ptr[i*row + j];
				if (w == M_Size) {
					w = 0; // new line for minor
					q++;
				}
			}
		}
	}
        if (this->ptr[a*row + b] != 0){ //optimization
            det += this->ptr[a*row + b] * ((a + b) % 2 ? -1 : 1) * local_matr.det();// sum parts of det
        }
        b++;
    }
    return det;
}

void matrix::setCol(size_t) {
	this->col = col;
}

void matrix::setRow(size_t) {
	this->row = row;
}
void matrix::read(void) {
	size_t aSize = row * col;
	for (int i = 0; i < aSize; i++)
        this->ptr[i] = num_scan();
}

void matrix::print(void)const {
    size_t aSize = row * col;
    for (int i = 0; i < aSize; i++) {
        if(i % row == 0 && i != 0)
            cout << endl;
        cout << setprecision(3) << setw(3) << " " << this->ptr[i];
    }
}

matrix matrix::auto_fill(void)const {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			this->ptr[i*row + j] = random_int(-9, 9);
		}
	}
}

matrix matrix::transp(void)const {
	matrix transp_matr(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			transp_matr.ptr[j*row + i] = this->ptr[i*row + j];
	return transp_matr;
}

matrix matrix::adjoint(void)const {
	if (row != this->getCol()) {
		cout << "Matrix have wrong size!" << endl;
		exit(1); //??
	}
	int M_Size = row - 1;
	matrix adjoint_matr(row, col);
	matrix local_matr(M_Size, M_Size);
	int n, m;
	for (int a = 0; a < row; a++) { //throw all elements
		for (int b = 0; b < col; b++) {
			int q = 0, w = 0; //reset indexes for local_matr
			for (int i = 0; i < row; i++) {//searching
				for (int j = 0; j < col; j++) { // minor
					if (i != a && j != b) {
						local_matr.ptr[q * M_Size + w++] = this->ptr[i *row + j];
						if (w == M_Size) {
							w = 0; // new line for minor
							q++;
						}
					}
				}
			}
			adjoint_matr.ptr[a*row + b] = ((a + b) % 2 ? -1 : 1) * local_matr.det();//sum parts of the det
		}
	}
	return adjoint_matr;
}

matrix matrix::inverse(void)const {
	int det = this->det();
	if (det == INT_MIN) {
		cout << "Matrix doesn/'t have inverse matrix\n";
			exit(1);
	}
	if (det == 0) {
		cout << "Determinator = " << det << endl;
		cout << "Matrix doesn/'t have inverse matrix\n";
			exit(1);
	}
	matrix adjoint = this->adjoint();
	matrix transp = adjoint.transp();
	matrix inverse = transp * (1.0 / det);
	return inverse;
}
matrix matrix::inverseGauss(void)const {
	if (row != this->getCol()) {
		cout << "Matrix have wrong size!" << endl;
		exit(1); //??
	}
	matrix inverse_matr(row, row); //don't change origin
	for (int i = 0; i < row; i++)
		inverse_matr.ptr[i* row + i] = 1;

	//direct detour: elements under main diagonal => 0
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			float multiplier = (float)this->ptr[j*row + i] / this->ptr[i*row + i];
			for (int c = 0; c < row; c++) { //substract line
				this->ptr[j * row + c] -= (float)multiplier * this->ptr[i*row + c]; // make 0
				inverse_matr.ptr[j * row + c] -= (float)multiplier * inverse_matr.ptr[i*row + c];
			}
		}
	}

	//bypass: elements above main diagonal => 0
    for (int i = 0; i < row - 1; i--) { // make main diagonal '1'
        float multiplier = this->ptr[i * row + i];
        for (int c = 0; c < row; c++) {
            this->ptr[i*row + c] /= (float)multiplier;
            inverse_matr.ptr[i *row + c] /= (float)multiplier;
        }
        for (int j = i - 1; i >= 0; j--) {
            multiplier = (float)this->ptr[j*row + i] / this->ptr[i*row + i];
            for (int c = 0; c < row; c++){ //substract line
                this->ptr[j*row + c] -= multiplier * this->ptr[i *row + c]; // make '0'
            inverse_matr.ptr[j*row + c] -= multiplier * inverse_matr.ptr[i * row + c];
            }
        }
    }
	return inverse_matr;
}


matrix matrix::operator *(matrix&) {
	if ( row != this->getCol() ) {
		cout << "Matrix have wrong size!" << endl;
		exit(1); //??
	}

	matrix result(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			for (int k = 0; k < row; k++)
				result.ptr[i * row + j] += this->ptr[i*row + k] * this->ptr[k*row + j];
	return result;
}

matrix matrix::operator *(float num) {
	matrix result(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			result.ptr[i * row + j] = this->ptr[i*row + j] * num;
	return result;
}

//read only int numbers
int num_scan(void) {
	int num = 0, proof = 0;
	do {
		proof = scanf("%d", &num);
		if (proof == 1) break;
		printf("Incorrect input, try again");
		fflush(stdin);
	} while (1);
	return num;
}

int random_int(int min, int max) {
	return rand() % (max - min + 1) + min;
}
