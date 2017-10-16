#include <iostream>
#include <valarray>     // заголовочный файл массивов значений
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));

    // создаем  два массива значений типа int на 5 элементов
    valarray<int> array1(5);
    valarray<int> array2(5);

    cout << "Первый массив: ";
    for(int i = 0; i < array1.size(); i++) {
        cout << (array1[i] = rand() % 10) << " ";
    }

    array2 = rand() % 10; // всем элементам массива array2 присвоили случайное значение
    cout << "\nВторой массив: ";
    for(int i = 0; i < array2.size(); i++) {
        cout << array2[i] << " ";
    }

    valarray<bool> res(5);

    res = (array1 < array2); // в результате выполнения этой операции возвращается массив булевых значений
    cout << "\nРезультат:     ";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}
