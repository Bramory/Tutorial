#include <cmath>
#include "calc.h"
#include "const.h"

//define global
const int N = 4;
const int y_size = 3; //order of function
float x_t[N], y[N];
float coeff[y_size]; // coefficients
//window parameters
int width =  500;
int height = 500;
int x_pos = 700;
int y_pos = 0;
int SCL = 30;


//amount of summands, coefficients, your X_point
float formula(int y_size, float coef[], float x_pt){
    float funcValue = 0;
    //out << "func = ";
    for(int i = y_size-1; i >= 0; i--){
        funcValue += (float) pow(x_pt, i) * coef[i];
        //cout << "+" << (float)pow(x_pt, i) << "*" << coef[i] << "(n=" << i << ") ";
    }
    //cout << endl;
return funcValue;
}

float sigmaB(float x[], int n, int k, int l){
    float sum = 0;
    for(int i = 0; i < n; i ++){
        sum += pow(x[i], k+l);
    }
    return sum;
}

float sigmaC(float x[], float y[], int n, int k){
    float sum = 0;
    for(int i = 0; i < n; i ++){
         sum += pow(x[i], k) * y[i];
    }
    return sum;
}
