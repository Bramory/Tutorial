#include <iostream>
#include <list>     // ���������� ��������� ������
#include <iterator> // ��������� ����������
#include <ctime>
#include <cstdlib>
#include <pthread.h>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
   list<int> myList; // ��������� ������ ������
   srand(time(NULL));

   for(int i = 0; i < 5; i++) {
       myList.push_back(rand()%5); // ��������� � ������ ����� ��������
   }
   cout << "������: ";
   copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));
    cout << endl;

    list<int> myList2; // ��������� ������ ������

   for(int i = 0; i < 5; i++) {
       myList2.push_back(rand()%9); // ��������� � ������ ����� ��������
   }
   cout << "������2: ";
   copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout," "));
    cout << endl;

   myList.sort();
   myList2.sort();
   cout << "������: ";
    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));
    cout << endl;
       cout << "������2: ";
   copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout," "));
    cout << endl;

    myList.merge(myList2);
   cout << "������: ";
   copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));
cout << endl;

   myList.unique();
   cout << "������1 merge: ";
   copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));
   cout << endl;

   cout << "������2: ";
   copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout," "));

   return 0;
}
