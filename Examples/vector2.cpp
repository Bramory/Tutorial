#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector <int> vecFirst ,vecSecond; /// Создаем два вектора
  for ( int i=0; i<10; ++i)
  {
      vecFirst.push_back(i); /// заполняем первый вектор
      vecSecond.push_back(i*10); /// заполняем второй вектор
  }

  cout << "vecFirst contains: ";
  for (int i=0; i<vecFirst.size(); ++i)
  cout << vecFirst[i] << " ";;

  cout << "\nvecSecond contains: ";
  for (int i=0; i<vecSecond.size(); ++i)
  cout << vecSecond[i] << " ";;

  vecFirst.swap(vecSecond); ///меняем местами элементы векторов

  cout << "\nvecFirst contains: ";
  for (int i=0; i<vecFirst.size(); ++i)
  cout << vecFirst[i] << " ";;

  cout << "\nvecSecond contains: ";
  for (int i=0; i<vecSecond.size(); ++i)
  cout << vecSecond[i] << " ";;

  swap (vecFirst.back(),vecSecond.back()); ///поменяли местами последний элемент в обоих векторах

  cout << "\nvecFirst contains: ";
  for (int i=0; i<vecFirst.size(); ++i)
  cout << vecFirst[i] << " ";;

  cout << "\nvecSecond contains: ";
  for (int i=0; i<vecSecond.size(); ++i)
  cout << vecSecond[i] << " ";;

  ///вместимость вектора до увеличения его размера
  cout << "\nvecFirst capacity before reserve: " << vecFirst.capacity();
  vecFirst.reserve(20);

  ///вместимость вектора после увеличения его размера
  cout << "\nvecFirst capacity after reserve: " << vecFirst.capacity();
  return 0;
}
