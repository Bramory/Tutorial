#include <iostream>
#include <valarray>     /// заголовочный файл массивов значений
#include <iomanip>

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    valarray<int> array(0, 60);

    /// определяем массивы обобщенного среза
    size_t length[] = {2, 8};   /// две серии, в каждой серии по 6 элементов ///почему появляется индекс 1, когда 8 эл в серии
    size_t stride[] = {4, 10};  /// шаг между сериями - 4 элемента, шаг между элементами одной серии - 10.

    /// создаем два объекта, в которые помещаем массивы срезов
    valarray<size_t> len(length, 2);
    valarray<size_t> str(stride, 2);

    array[gslice(2, len, str)] = 1; /// по срезу присваиваем всем элементам подмножества единицу

    cout << "Измененный массив значений: ";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    cout << "\nПодмножество(индексы элементов массива): ";
    for(int i = 0, j = 0; i < array.size(); i++, j++) {
            if ( array[i] == 1) {
                cout << setw(2) << i << " ";
            }
    }
    return 0;
}
