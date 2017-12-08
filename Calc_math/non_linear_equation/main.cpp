#include <iostream>
#include <cstdlib>
#define pi 3.141592
#include <math.h>
using namespace std;
float x[200],y[200],y2[200],e,x2[200];
int i;

double F(double a){
    return log(a);
}

int main(){
    cin >> x[0] >> e;
    i=-1;

    double (*func)(double) = F;
    do
    {
        i++;
        y[i]= F(x[i]);
        y2[i] = (float) 1/x[i];
        x[i+1]=x[i]-y[i]/y2[i];
    }
    while (fabs(x[i+1]-x[i])>e);
    cout <<  x[i+1] << endl;

    system("pause");
    return 0;
}
