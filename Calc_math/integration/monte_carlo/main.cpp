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
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::max;
//using namespace std;

float random_float(float min, float max) {
	return rand() * (max - min)/RAND_MAX + min;
}

///integral from 0 to 1 looks nicely
double XX (double x){
return pow(x, x);
}

const int pts = 300;
int pts_inside = 0;
Point pts_ptr[pts];
float y_lim;
float left;
float right; //intervals

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    draw_net();      // Cartesian system


    ///draw empiric formula -> approximate graph
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_STRIP);
    for(float x = -width; x < width; x += 0.1)
        glVertex2f(x*SCL, formula(y_size, coeff, x)*SCL);
    glEnd();

    ///draw Log(x)
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_STRIP);
    for(float x = -width; x < width; x += 0.1)
        glVertex2f(x*SCL, log(x)*SCL);
    glEnd();

    ///rectangular for cramped square in interval
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);
        glVertex2f(left * SCL, 0*SCL); //left bottom
        glVertex2f(left * SCL, y_lim*SCL); //left up
        glVertex2f(right * SCL, y_lim*SCL); //right up
        glVertex2f(right * SCL, 0*SCL); //right bottom
    glEnd();

    /// random points
    glColor3f(0, 1, 0);
    glPointSize(2);
    glBegin(GL_POINTS);
    for(int i = 0; i < pts; i ++)
        glVertex2f(pts_ptr[i].x * SCL, pts_ptr[i].y * SCL);
        //drawCircle(pts_ptr[i].x * SCL, pts_ptr[i].y * SCL, 4, 30);
    glEnd();

    /// Our Points from table
    glColor3f(1, 0, 0);
    for(int i = 0; i < N; i ++)
        drawCircle(x_t[i]*SCL, y[i]*SCL, 5, 20);

    glutSwapBuffers();
}

void timer(int a){
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

int main(int argc, char *argv[]) {

    srand(time(0));
    double(*func)(double) = log;

	float h = 1, first = 2;
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
    float x_pt = 3.2;
	//cin >> x_pt;

/////////////////////  Monte
	cout << "Enter first interval [a, b]:" << endl;
    cin >> left >> right;
    y_lim = max(func(left), func(right));
    cout << "HIGH LIMIT = " << y_lim << endl;

    for(int i = 0; i < pts; i ++){
        pts_ptr[i].x = random_float(left, right);
        pts_ptr[i].y = random_float(0, y_lim);
        if(pts_ptr[i].y < log(pts_ptr[i].x))
            pts_inside++;
    }
    cout << endl;

    float square = (right-left) * y_lim;
    cout << "Left Limit = " << left << endl;
    cout << "Right Limit = " << right << endl;
    cout << "Pseudo Square = " << square << endl;
    square = (float) square * pts_inside / pts;
    float abs_square = right * (log(right) - 1) - left * (log(left) - 1);
    cout << "All Points: " << pts << endl;
    cout << "Points inside: " << pts_inside << " ("  << (float) pts_inside/pts * 100 << " %)" << endl;

	cout << "Abs_square: " << "" << "(" << x_pt << ") = " << abs_square << endl;
	cout << "Calculate : " << "" << "(" << x_pt << ") = " << square << endl;
	float abs_err = abs_square - square;
	cout << "Absolute error: " << abs_err << endl;
	cout << "Relative error: " << abs_err / abs_square * 100 << " %" << endl;

    system("color 78"); //good print
    //Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_pos, y_pos);
    glutCreateWindow("Statistic_square");
    //glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SKeyboard);
    glutTimerFunc(100, timer, 0);
    //Registration
    glutDisplayFunc(display);
    Initialize();
    glutMainLoop();
    return 0;
}
