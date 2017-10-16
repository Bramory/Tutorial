#include <iostream>
#include <queue>        // ���������� ������������ ���� �������
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    priority_queue<float> myPrQueue;   // ������� ������ ������������ ������� ���� float

    // ������� � ������� ��������� ��������� ���� float
    myPrQueue.push(1);
    myPrQueue.push(6);
    myPrQueue.push(-1);
    myPrQueue.push(2);
    myPrQueue.push(-3);
    myPrQueue.push(15);

    cout << "���������� ��������� � �������: " << myPrQueue.size() << endl;
    cout << "������� ��������� � ������������ �������: ";

    // ��������� �������� ������� �� ������, � ������� �� ����������
    while(!myPrQueue.empty()) {
        cout << myPrQueue.top() << " ";
        myPrQueue.pop();
    }
    return 0;
}
