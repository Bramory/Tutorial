#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matrix.h"
using namespace std;

int main(void) {
    srand(time(0));
    setlocale(LC_CTYPE, "rus");
    const int n=3; //����������� �������
    float a[n][n+1],a0[n][n+1];    //A - ����������� ������� �������, A0 - �� ����� ��� �������� �������
    float mult,x[n],b[n];
    cout << "������� � ������ ������ �����";
    for (int i=0; i<n; i++) {
        cout << endl;
        for (int j=0; j<n+1; j++) {
            a0[i][j]=a[i][j]=1+rand()%100; /// ������� �� ���� �� �����
            cout << a[i][j] << " ";
        }
    }

    //������ ��� ������ ������
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++) {
            mult=a[i][i]/a[j][i];
        for (int k=0;k<=n;k++)
            a[j][k]= a[j][k]*mult-a[i][k];
    }
    //�������� ��� ������ ������
    x[n-1] = a[n-1][n]/a[n-1][n-1];
    for (int i=n-2;i>=0;i--) {
        mult=0;
    for (int j=i+1;j<n;j++)
        mult+=a[i][j]*x[j];
        x[i]=(a[i][n]-mult)/a[i][i];
    }

    cout << endl << "�������" << endl;
    for (int i=0; i<n; i++)
        cout << x[i] << " ";

    cout << endl << "��������" << endl;
    for (int i=0; i<n; i++) {
        b[i]=0;
        for (int j=0; j<n; j++) b[i]+=a0[i][j]*x[j];
        cout << b[i] << " ";
    }


//    int x, y;
//	cout << "Enter matrix size, please" << endl;
//	cin >> x;
//	cin >> y;
//	matrix MyMatr(x, y);
//	cout << "Enter " << x*y <<" numbers:" << endl;
//	MyMatr.read();
//	MyMatr.print();
//	matrix inverse = MyMatr.inverseGauss();
//
//
// cout << "Inverse Matrix :" << endl;
// inverse.print();

return 0;
}
