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

  ///���-�� ���������
  cout << "\nsize: " <<     vecFirst.size() <<  endl;



  ///���-�� ���������, ������� ����� ��������� ��� ������
  cout << "Capacity of vecFirst before clear: " << vecFirst.capacity();
  vecFirst.clear();

  ///���-�� ���������, ������� ����� ��������� ��� ������ ����� �������� ���� ���������
  cout << "\nCapacity of vecFirst after clear: " << vecFirst.capacity();
  vecFirst.shrink_to_fit();

  ///�������� ������
  cout << "\nCapacity of vecFirst after shrink_to_fit: " << vecFirst.capacity();

  return 0;
}
