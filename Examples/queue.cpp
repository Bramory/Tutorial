#include <iostream>
#include <queue>        // ���������� ������������ ���� �������
#include <string>       // ������������ ���� ��� ������ �� �������� ���� string
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    queue<string> myQueue;     // ������� ������ ������� ���� string

    // �������� � ������� ��������� ��������� ���� string
    myQueue.push("No pain ");
    myQueue.push("- no gain");

    cout << "���������� ��������� � �������: " << myQueue.size() << endl;
    cout << "\n��� ���: " << myQueue.front() << myQueue.back();

    myQueue.pop(); // ������� ���� ������� � �������
    cout << "\n������ � ������� ������� ���� �������: " << myQueue.front();
    return 0;
}
