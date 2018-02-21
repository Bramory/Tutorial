#include <cmath>
#include <iostream>
#include <stdio.h>
#include "calc.h"
#include "const.h"
using namespace std;

long long int fact(int a){
	long long int r = 1;
	for (int i = 1; i <= a; i++)
        r *= i;
	return r;
}


