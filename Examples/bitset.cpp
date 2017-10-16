#include <iostream>
#include <bitset>   // ������������ ���� ������� �����
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int number;
    cout << "������� ����� ����� �� 1 �� 255: ";
    cin >> number;

    bitset<8> message(number);
    cout << number << " = " << message << endl;

    bitset<8> bit2 = message;
    message = message.flip(); // �������� ��� ���� �� ���������������
    cout << "��������������� �����: " << message << endl;

    bitset<8> bit3 = bit2 | message;
    cout << bit2 << " | " << message << " = " << bit3 << endl; // �������� ����������� ���

    bitset<8> bit4 = bit3 & message;
    cout << bit3 << " & " << message << " = " << bit4 << endl; // �������� ����������� �

    bitset<8> bit5 = bit3 ^ message;
    cout << bit3 << " ^ " << message << " = " << bit5 << endl; // �������� ������������ ���
    return 0;
}
