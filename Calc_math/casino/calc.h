#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED


long long int fact(int a);
float** init(int aSize);
float** T(float** a, int aSize);
float** getDiffTable(float *a, int aSize);
float Q(float x, float x0, float h, int n);
float Stirling(float x);






#endif // CALC_H_INCLUDED
