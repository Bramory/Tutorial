#include <iostream>
#include <valarray>     /// ������������ ���� �������� ��������
#include <iomanip>

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    valarray<int> array(0, 60);

    /// ���������� ������� ����������� �����
    size_t length[] = {2, 8};   /// ��� �����, � ������ ����� �� 6 ��������� ///������ ���������� ������ 1, ����� 8 �� � �����
    size_t stride[] = {4, 10};  /// ��� ����� ������� - 4 ��������, ��� ����� ���������� ����� ����� - 10.

    /// ������� ��� �������, � ������� �������� ������� ������
    valarray<size_t> len(length, 2);
    valarray<size_t> str(stride, 2);

    array[gslice(2, len, str)] = 1; /// �� ����� ����������� ���� ��������� ������������ �������

    cout << "���������� ������ ��������: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    cout << "\n������������(������� ��������� �������): ";
    for(int i = 0, j = 0; i < array.size(); i++, j++) {
            if ( array[i] == 1) {
                cout << setw(2) << i << " ";
            }
    }
    return 0;
}
