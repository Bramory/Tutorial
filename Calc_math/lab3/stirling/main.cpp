#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

inline float q(float x, float x0, float h){ return (x - x0) / h; }

float** init(int size);
float** T(float** a, int size);
float** getDiffTable(float *a, int size);
long long int fact(int); //���������
float* getLogTable(float, float, int);
float Q(float, float, float, int); //���������� ������� q
void showDiffTable(float, float, float** a, int size);

int main(void){
	setlocale(LC_ALL, "Russian");
	int size = 7; //������ �������
	float h = 1; //���
	float first = 2; //������ �������
	float *a = new float[size];
	a = getLogTable(first, h, size); //�������� �������� y = ln(x)
	float x;
	float **y;
	y = getDiffTable(a, size); //�������� ������� ���������
	showDiffTable(first, h, y, size); //������� ��
	cout << "������� �������� ���������, ��� ���������� ������������ ���������: ";
	cin >> x;
	int mid = ceil((float)(size / 2)); //������� �������
	float x0 = first + h*mid;
	float P = y[mid][0]; //��������� ������� �������� ��������
	float temp1, temp2, temp3;
	for (int n = 1; n <= mid; n++){
		temp1 = Q(x, x0, h, n) / fact(2 * n - 1);
		temp2 = (y[-n + mid][2 * n - 1] + y[-(n - 1) + mid][2 * n - 1]) / 2;
		temp3 = (Q(x, x0, h, n)*q(x, x0, h)) / fact(2 * n);
		P += (temp1)*(temp2)+(temp3)*(y[-n + mid][2 * n]); //�������� �������� _���_ �������� ��������
		cout << (temp1)*(temp2) << "\n";
		cout << (temp3)*(y[-n + mid][2 * n]) << "\n";
	}
	cout << "������ q:  " << q(x, x0, h) << "\n";
	cout << "����������� ��������:  " << P << "\n";
	cout << "�������� ��������:  " << log(x) << "\n"; //������� �������� �������� (������������)
	cout << "���������� �����������:  " << fabs(P - log(x)) << "\n"; //���������� �����������
	cout << "������������� �����������:  " << fabs(P - log(x)) / log(x) * 100 << "%\n"; //������������� �����������

	system("pause");
	return 0;
}

long long int fact(int a){
	long long int r = 1;
	for (int i = 1; i <= a; i++) r *= i;
	return r;
}

float** init(int size){
	float** res;
	res = new float*[size];
	for (int i = 0; i<size; i++)
	{
		res[i] = new float[size - i];
	}
	return res;
}

float** T(float** a, int size){
	float** res;
	res = init(size);
	for (int i = 0; i<size; i++){
		for (int j = 0; j<size - i; j++){
			res[i][j] = a[j][i];
		}
	}
	return res;
}

float** getDiffTable(float *a, int size){
	float** res;
	res = init(size);
	res[0] = a;
	for (int i = 1; i<size; i++){
		for (int j = 0; j<=size - i; j++){
			res[i][j] = res[i - 1][j + 1] - res[i - 1][j];
		}
	}
	return T(res, size);
}

float Q(float x, float x0, float h, int n){
	float res = q(x, x0, h);
	for (int i = 1; i<n; i++){
		res *= (q(x, x0, h)*q(x, x0, h) - i*i);
	}
	return res;
}

float* getLogTable(float first, float h, int n){
	float *res = new float[n];
	float x = first;
	for (int i = 0; i<n; i++){
		res[i] = log(x);
		x += h;
	}
	return res;
}

void showDiffTable(float first, float h, float** a, int size){
	for (int i = 0; i<size; i++){
		printf("%3.2f\t", first + h*i);
		for (int j = 0; j<size - i; j++){
			printf("%3.2f\t", a[i][j]);
		}
		cout << "\n";
	}
}
