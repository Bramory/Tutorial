#include <stdio.h>
#include <math.h>

typedef double (*FUNCP)(double);

double GaussMethodIntegral(FUNCP fp, double a, double b);
double Gyperbola(double x), Parabola(double x);

/* вычисляет интегралы функций методом Гаусса */
int main(void)
{
    FUNCP funcs[10];
    int i;

    funcs[0] = Gyperbola;
    funcs[1] = Parabola;

    for (i = 0; i < 2; i++)
        printf("%f\n", GaussMethodIntegral(funcs[i], 1.0/2, 4.0));
    return 0;
}

/* GaussMethodIntegral:  вычисляет интеграл для функции fp методом Гаусса */
double GaussMethodIntegral(FUNCP fp, double a, double b)
{
    return (b-a)/2 * (
         fp((a+b)/2 - (b-a)/(2*sqrt(3))) +
         fp((a+b)/2 + (b-a)/(2*sqrt(3)))
         );
}

/* Gyperbola:  вычисляет значение гиперболы */
double Gyperbola(double x)
{
    return 1/x;
}

/* Parabola:  вычисляет значение параболы */
double Parabola(double x)
{
    return x*x;
}
