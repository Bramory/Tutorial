#include <iostream>
#include <bitset>   // заголовочный файл битовых полей
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int number;
    cout << "Введите целое число от 1 до 255: ";
    cin >> number;

    bitset<8> message(number);
    cout << number << " = " << message << endl;

    bitset<8> bit2 = message;
    message = message.flip(); // поменять все биты на противоположные
    cout << "Инвертированное число: " << message << endl;

    bitset<8> bit3 = bit2 | message;
    cout << bit2 << " | " << message << " = " << bit3 << endl; // операция логического ИЛИ

    bitset<8> bit4 = bit3 & message;
    cout << bit3 << " & " << message << " = " << bit4 << endl; // операция логического И

    bitset<8> bit5 = bit3 ^ message;
    cout << bit3 << " ^ " << message << " = " << bit5 << endl; // операция исключающего ИЛИ
    return 0;
}
