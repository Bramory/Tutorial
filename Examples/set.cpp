#include <iostream>
#include <set>  // ������������ ���� �������� � ��������������
#include <iterator>

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    set<char> mySet; // �������� ������ ���������

    // ��������� �������� � ���������
    mySet.insert('I');
    mySet.insert('n');
    mySet.insert('f');
    mySet.insert('i');
    mySet.insert('n');
    mySet.insert('i');
    mySet.insert('t');
    mySet.insert('y');

    copy( mySet.begin(), mySet.end(), ostream_iterator<char>(cout, " "));
    return 0;
}
