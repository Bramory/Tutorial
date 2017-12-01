#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

typedef struct Point{
    float x, y;
}Point;

//amount of summands, coefficients, your X_point
float formula(int y_size, float coef[], float x_pt);

float sigmaB(float x[], int n, int k, int l);

float sigmaC(float x[], float y[], int n, int k);

#endif // CALC_H_INCLUDED
