#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

/// x may be bigger than 1,
/// we take a look on the integer line: 1, 4, 9, 16, 25... with self-hard-code
float XX (float x){
//float res = x;
//    for (int i = 0; i < x; i++){
//        res *= x;
//    }
return pow(x, x);
}

int main(int argc, char* argv[]){
	system("color 78");
	float a, b;
	const int N = 4;
	float Ai[N], ti[N], Ci[N]; //table values
	float X[N], Y[N], part[N];  // chosen nodes
	float (*func)(float) = log; // our function ptr

    switch(N){
		case 3:
		    ti[0] = -0.7745966;
			ti[1] = 0.0;
			ti[2] = 0.7745966;

            Ai[0] = Ai[2] = 0.5555555;
			Ai[1] = 0.8888889;
			break;
		case 4:
		    ti[0] = -0.8611363;
			ti[1] = -0.3399810;
			ti[3] = 0.8611363;
			ti[2] = 0.3399810;

            Ai[0] = Ai[3] = 0.3478548;
			Ai[1] = Ai[2] = 0.6521451;
			break;
	}

	cout << "The program compute the integral of the func (X) by the Gauss method, N = "<< N <<".\n"
	<< "Enter the integration limits. a - lower, b - upper" << endl;
	cout << "Enter: a, b [ > 0]" << endl;
	cin >> a >> b;
	float result = 0;

	for(int i = 0; i < N; i++){
		X[i] = (b + a)/2.0 + ((b - a) * ti[i]) / 2.0;
		Ci[i] = (b - a) / 2.0 * Ai[i];
		Y[i] = func(X[i]);
		part[i] = Y[i] * Ci[i]; // SUM = Sigma ( parts Y*Ci )
		result += part[i];
	}

	cout <<"    Xi \t\t Yi \t\t Ci \t\t Ci*Yi " << endl;
	for(int i = 0; i < N; i++){
	    cout << i+1 << ") " << setw(7) << setprecision(7)
	    << X[i]  << "\t" << Y[i]  << "\t" << Ci[i] << "\t" << part[i] << endl;
	}
	cout << endl << "\t\t\t\t\t  Sum = " << setprecision(7) << result << endl ;

    float abs_answer = b*(func(b) - 1) - a * (func(a) - 1);
	cout << "Abs_answer: " << "S(" << a << ".." << b << ") = " << abs_answer << endl;
	cout << "Calculate : " << "S(" << a << ".." << b << ") = " << result << endl;
	float abs_err = abs(abs_answer - result);
	cout << "Absolute error: " << abs_err << endl;
	cout << "Relative error: " << (abs_answer == 0 ? 0 :(abs_err / abs_answer * 100) ) << " %" << endl;

	system("pause");
	return 0;
}
