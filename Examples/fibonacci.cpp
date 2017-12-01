#include <iostream>
#include <iomanip>
using namespace std;

long double fibb(int n){
    int ch1 = 0, num = 1, sum;
    if (n < 0){
        cout << "Incorrect input" << endl;
        return -1;
    }
    else if (n == 0)
        return ch1;

    for (int i = 1; i < n; i++){
        sum = ch1 + num;
        ch1 = num;
        num = sum;
    }
    return num;
}

int main(){
    int n = 10, sum = 0;
    cout << "Enter amount of months: ";
    cin >> n;
    for (int i = 2; i <= n+2; i++)
    	cout << "Rabbits in #" << i << " = " << fibb(i) << endl;

 	cout << endl;
return 0;
}
