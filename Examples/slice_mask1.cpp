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

    array[array> 5 && array < 8] = -1; // �� ����� ����������� �������� -1

    cout << "\n���������� ������ ��������: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    return 0;
}
