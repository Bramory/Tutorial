#include <iostream>

using namespace std;
#include "stack.h"

int main()
{
    setlocale(LC_CTYPE, "rus");

    size_t aSize = 6;
    Stack<char> stackSymbol(aSize);
    int ct = 0;
    char ch;

    while (ct++ < aSize)
    {
        cin >> ch;
        stackSymbol.push(ch); // �������� �������� � ����
    }

    cout << endl;

    stackSymbol.printStack(); // ������ �����

    cout << "\n\n������ ������� �� �����\n";
    stackSymbol.pop();

    stackSymbol.printStack(); // ������ �����

    Stack<char> newStack(stackSymbol);

    cout << "\n\n�������� ����������� �����������!\n";
    newStack.printStack();


    cout << "������ � ������� �������: "<< newStack.Peek(2) << endl;

    return 0;
}
