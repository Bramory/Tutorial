//метод наименьших квадратов
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "const.h"
#include "draw.h"
#include "calc.h"
using namespace std;

int main(int argc, char *argv[]) {
    srand(time(0));
	int h = 1;
	float first = 2;
	cout << "Enter first X from table:" << endl;
	//cin >> first;
	cout << "Enter step (h):" << endl;
	//cin >> h;

    ///order of empiric function
	int x_size = y_size + 1; //extended matrix
	float a[y_size][x_size];
	//enter table of begin values: x, y
	for(int i = 0; i < N; i++) {
		x_t[i] = first + i*h;
        y[i] = log(x_t[i]); // Our function
	}

	cout << "X values:" << endl;
    for(int i = 0; i < N; i++) {
		cout << x_t[i] << " ";
	}
	cout << endl;

	cout << "Y values:" << endl;
    for(int i = 0; i < N; i++) {
		cout << y[i] << " ";
	}

    //init array, set values = 0
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < y_size; j++) {
			a[i][j] = sigmaB(x_t, N, i, j);
		}
	}
	for (int i = 0; i < y_size; i++) {
        a[i][y_size] = sigmaC(x_t, y, N, i);
	}

	///lets solve our system with Gauss method
    float mult;
    //print matrix on the screen
    cout << endl << "Our Matrix: " << endl;
    for (int i=0; i<y_size; i++) {
        for (int j=0; j<y_size+1; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    //Straight Gauss
    for (int i=0;i<y_size-1;i++)
        for (int j=i+1;j<y_size;j++) {
            mult=a[i][i]/a[j][i];
        for (int k=0;k<=y_size;k++)
            a[j][k]= a[j][k]*mult-a[i][k];
    }
    //Inverse Gauss
    coeff[y_size-1] = a[y_size-1][y_size]/a[y_size-1][y_size-1];
    for (int i=y_size-2;i>=0;i--) {
        mult=0;
    for (int j=i+1;j<y_size;j++)
        mult+=a[i][j]*coeff[j];

        coeff[i]=(a[i][y_size]-mult)/a[i][i];
    }

    cout << endl << "A2, A1, A0:" << endl;
    for (int i=y_size-1; i>=0; i--)
        cout << coeff[i] << " ";

    cout << endl;
    cout << "Enter point X:" << endl;
    float x_pt = 5.2;
	//cin >> x_pt;
            ///   like:    a2 * x ^2 +    a1 * x     + a0
    float Y = formula(y_size, coeff, x_pt);//(x[2] * x_pt * x_pt) + (x[1] * x_pt) + x[0];
	cout << "Abs_answer: " << "log" << "(" << x_pt << ") = " << log(x_pt) << endl;
	cout << "Calculate : " << "log" << "(" << x_pt << ") = " << Y << endl;
	double abs_err = abs(Y - log(x_pt));
	cout << "Absolute error: " << abs_err << endl;
	cout << "Relative error: " << abs_err / log(x_pt) * 100 << " %" << endl;


    system("color 78"); //good print
    //Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_pos, y_pos);
    glutCreateWindow("Least squares");
    //Registration
    glutDisplayFunc(display);
    Initialize();
    glutMainLoop();
    return 0;
}
