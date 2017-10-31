#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
  vector <int> vecFirst;
  vecFirst.reserve(100);
   vecFirst.insert(vecFirst.end(), 4);
   vecFirst.insert(vecFirst.end(), 3);


copy(vecFirst.begin(), vecFirst.end(), ostream_iterator<int>(cout," ") );

  ///кол-во элементов
  cout << "\nsize: " <<     vecFirst.size() <<  endl;



  ///кол-во элементов, которое может содержать наш вектор
  cout << "Capacity of vecFirst before clear: " << vecFirst.capacity();
  vecFirst.clear();

  ///кол-во элементов, которое может содержать наш вектор после удаления всех элементов
  cout << "\nCapacity of vecFirst after clear: " << vecFirst.capacity();
  vecFirst.shrink_to_fit();

  ///очищение памяти
  cout << "\nCapacity of vecFirst after shrink_to_fit: " << vecFirst.capacity();

  return 0;
}
