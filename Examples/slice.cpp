#include <iostream>
#include <valarray>     // ������������ ���� �������� ��������

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    valarray<int> array(1, 30);
    cout << "������: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    array[slice(2, 5, 4)] = 2; // ���� ��������� �������, ������� � ������� 2 � ����� � 4 �������� ��������� �������� 5
    array[slice(0, 7, 3)] = 3; // ���� ��������� �������, ������� � ������� 0 � ����� � 3 �������� ��������� �������� 2

    cout << "\n������ ����� ���������� ������: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
s
    // ������� � �������� ��������, �������� 10 ��������� � �������, � ����� - 2
    array[slice(0, 10, 2)] = pow(static_cast<valarray<int> >(array[slice(0, 10, 2)]), 2);

    cout << "\n������ ��������� ������ ���������: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    return 0;
}
