#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector <int> vecInt(3,100); ///Создаем вектор из 3 элементов и заполняем его значением 100
   vector <int>::iterator it;
   it = vecInt.begin(); ///Итератор указывает на vec[0]

   ///Вектор расширяется теперь до 4 элементов
   vecInt.insert (it,200); ///И первым элементом записывается 200

   ///Вектор расширяется теперь до 5 элементов
   it = vecInt.begin() + 3;///Вектор указывает на 4 элемент (0-элемент+3-элемента)
   vecInt.insert(it,300);///И четвертым элементом записывается 300
   vecInt.insert(it+1,900);///Вектор расширяется теперь до 6 элементов и 5 элементом записывается 900

   cout << "Vector contains: ";
   for (int i=0; i<vecInt.size(); ++i)
   {
      cout << vecInt[i] << " ";
   }

   cout << "\nVector max_size: " << vecInt.max_size();
   cout << "\nVector size: " << vecInt.size(); ///Выводим размер вектора
   vecInt.resize(10); ///Увеличиваем размер до 10 элементов
   cout << "\nNew vector size: " << vecInt.size() << endl; ///Выводим размер вектора
   return 0;
}
