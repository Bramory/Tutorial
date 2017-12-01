//метод наименьших квадратов
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "keyboard.h"
#include "const.h"
#include "draw.h"
#include "calc.h"
using namespace std;

float parabola(float x){
    return x*x;
}

float gyperbola(float x){
    return 1.0/x;
}

int main(int argc, char *argv[]) {
    srand(time(0));

    float(*func)(float) = log;

	float h = 1;
	float first = 2;
	cout << "Enter first X from table:" << endl;
	cin >> first;
	cout << "Enter step (h):" << endl;
	cin >> h;

    ///order of empiric function
	int x_size = y_size + 1; //extended matrix
	float a[y_size][x_size];
	//enter table of begin values: x, y
	for(int i = 0; i < N; i++) {
		x_t[i] = first + i*h;
        y[i] = func(x_t[i]); // Our function
	}

	cout << "   X \t Y" << endl;
    for(int i = 0; i < N; i++) {
		cout << i << ") " << x_t[i] << "\t" << y[i] << endl;
	}
	cout << endl;

    //init array, set values = 0
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < y_size; j++) {
			a[i][j] = sigmaB(x_t, N, i, j);
		}
	}
	for (int i = 0; i < y_size; i++) {
        a[i][y_size] = sigmaC(x_t, y, N, i);
	}

    //print matrix on the screen

    cout << endl << "Our Matrix: " << endl;
    for (int i=0; i<y_size; i++) {
        for (int j=0; j<y_size+1; j++) {
            cout << setw(3) << setprecision(4)  << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    ///lets solve our system with Gauss method
    //Straight Gauss
    float mult;
    for (int i=0;i<y_size-1;i++)
        for (int j=i+1;j<y_size;j++) {
            mult=a[i][i]/a[j][i];
        for (int k=0;k<=y_size;k++)
            a[j][k]= a[j][k]*mult-a[i][k];
    }
    //Inverse Gauss
    //bottom last coeff
    coeff[y_size-1] = a[y_size-1][y_size] / a[y_size-1][y_size-1];
    for (int i=y_size-2;i>=0;i--) {
        mult = 0;
    for (int j=i+1;j<y_size;j++)
        mult+=a[i][j]*coeff[j];

        coeff[i]=(a[i][y_size]-mult)/a[i][i];
    }

    cout << endl << "A2, A1, A0:" << endl;
    for (int i = y_size-1; i>=0; i--)
        cout  << setprecision(6) <<  coeff[i] << " ";

    cout << endl;
    cout << "Enter point X:" << endl;
    float x_pt = 5.2;
	cin >> x_pt;
    float Y = formula(y_size, coeff, x_pt);//(x[2] * x_pt * x_pt) + (x[1] * x_pt) + x[0];
	cout << "Abs_answer: " << "func" << "(" << x_pt << ") = " << func(x_pt) << endl;
	cout << "Calculate : " << "func" << "(" << x_pt << ") = " << Y << endl;
	double abs_err = abs(Y - func(x_pt));
	cout << "Absolute error: " << abs_err << endl;
	cout << "Relative error: " << abs_err / func(x_pt) * 100 << " %" << endl;

    system("color 78"); //good print
    //Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_pos, y_pos);
    glutCreateWindow("Least squares");
    //glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SKeyboard);
    //Registration
    glutDisplayFunc(display);
    Initialize();
    glutMainLoop();
    return 0;
}
