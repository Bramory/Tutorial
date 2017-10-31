#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector <int> vecFirst ,vecSecond; /// ������� ��� �������
  for ( int i=0; i<10; ++i)
  {
      vecFirst.push_back(i); /// ��������� ������ ������
      vecSecond.push_back(i*10); /// ��������� ������ ������
  }

  cout << "vecFirst contains: ";
  for (int i=0; i<vecFirst.size(); ++i)
  cout << vecFirst[i] << " ";;

  cout << "\nvecSecond contains: ";
  for (int i=0; i<vecSecond.size(); ++i)
  cout << vecSecond[i] << " ";;

  vecFirst.swap(vecSecond); ///������ ������� �������� ��������

  cout << "\nvecFirst contains: ";
  for (int i=0; i<vecFirst.size(); ++i)
  cout << vecFirst[i] << " ";;

  cout << "\nvecSecond contains: ";
  for (int i=0; i<vecSecond.size(); ++i)
  cout << vecSecond[i] << " ";;

  swap (vecFirst.back(),vecSecond.back()); ///�������� ������� ��������� ������� � ����� ��������

  cout << "\nvecFirst contains: ";
  for (int i=0; i<vecFirst.size(); ++i)
  cout << vecFirst[i] << " ";;

  cout << "\nvecSecond contains: ";
  for (int i=0; i<vecSecond.size(); ++i)
  cout << vecSecond[i] << " ";;

  ///����������� ������� �� ���������� ��� �������
  cout << "\nvecFirst capacity before reserve: " << vecFirst.capacity();
  vecFirst.reserve(20);

  ///����������� ������� ����� ���������� ��� �������
  cout << "\nvecFirst capacity after reserve: " << vecFirst.capacity();
  return 0;
}
