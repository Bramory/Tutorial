#include <iostream>
#include <valarray>     // заголовочный файл массивов значений

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    valarray<int> array(1, 30);
    cout << "Массив: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    array[slice(2, 5, 4)] = 2; // пяти элементам массива, начиная с индекса 2 с шагом в 4 элемента присвоить значение 5
    array[slice(0, 7, 3)] = 3; // семи элементам массива, начиная с индекса 0 с шагом в 3 элемента присвоить значение 2

    cout << "\nМассив после применения срезов: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
s
    // начиная с нулевого элемента, возвести 10 элементов в квадрат, с шагом - 2
    array[slice(0, 10, 2)] = pow(static_cast<valarray<int> >(array[slice(0, 10, 2)]), 2);

    cout << "\nМассив квадратов четных элементов: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    return 0;
}
