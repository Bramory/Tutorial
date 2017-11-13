#include <iostream>

#include <valarray>     // ������������ ���� �������� ��������
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    valarray<int> array(0, 15);
    cout << "�������� �������: ";
    for(int i = 0; i < array.size(); i++) {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }

    //���������� ������������ (��� ������ ��� ������������ ����������� ������ ���� size_t)
    valarray<size_t> index(5);
    index[0] = 7;
    index[1] = 12;
    index[2] = 14;
    index[3] = 2;
    index[4] = 0;

    valarray<int> array2(array[index]); // ��������� �������� ������������ ������� ������� ��������
    cout << "\n�������� ������������: ";
    for(int i = 0; i < array2.size(); i++) {
        cout << array2[i] << " ";
    }

    array[index] = 99; // ���� ��������� ������������ ��������� �������� 99
    cout << "\n���������� ������ ��������: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    return 0;
}
