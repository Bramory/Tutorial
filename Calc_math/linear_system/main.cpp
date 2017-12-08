// Метод Жордана_Гаусса
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

//return numbers from [a ... b]
int randomIntFromRange (int min, int max){
    return rand() % (max-min+1) + min;
}

int main(int argc, char *argv[]) {
    srand(time(0));
    double(*func)(double) = log;

	int y_size = 3;
	float coeff[y_size] ;
    ///order of empiric function
	int x_size = y_size + 1; //extended matrix
	float a[y_size][x_size];
	//enter table of begin values: x, y
    for (int i=0; i<y_size; i++) {
        for (int j=0; j<y_size+1; j++) {
            cin >> a[i][j];
            //a[i][j] = randomIntFromRange(0, 10);
        }
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


    system("color 78"); //good print
    system("pause");
	return 0;
}
