#include <iostream>
#include <valarray>     // ������������ ���� �������� ��������
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));

    // �������  ��� ������� �������� ���� int �� 5 ���������
    valarray<int> array1(5);
    valarray<int> array2(5);

    cout << "������ ������: ";
    for(int i = 0; i < array1.size()-1; i++) {
        cout << (array1[i] = i) << " ";
    }
    cout << (array1[array1.size()-1] = -1);


    array2 = rand() % 6; // ���� ��������� ������� array2 ��������� ��������� ��������
    cout << "\n������ ������: ";
    for(int i = 0; i < array2.size(); i++) {
        cout << array2[i] << " ";
    }

    valarray<bool> res(5);

    res = (array1 < array2); // � ���������� ���������� ���� �������� ������������ ������ ������� ��������
    cout << "\n���������:     ";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

     cout << "\nSum arr2     "<< endl;
    cout << array2.sum() << endl;
     cout << "\nmax arr1     "<< endl;
    cout << array1.max() << endl;
     cout << "\nmin arr1     "<< endl;
    cout << array1.min() << endl;

    return 0;
}
