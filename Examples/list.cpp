#include <iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов
#include <ctime>
#include <cstdlib>
#include <pthread.h>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
   list<int> myList; // объявляем пустой список
   srand(time(NULL));

   for(int i = 0; i < 5; i++) {
       myList.push_back(rand()%5); // добавляем в список новые элементы
   }
   cout << "Список: ";
   copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));
    cout << endl;

    list<int> myList2; // объявляем пустой список

   for(int i = 0; i < 5; i++) {
       myList2.push_back(rand()%9); // добавляем в список новые элементы
   }
   cout << "Список2: ";
   copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout," "));
    cout << endl;

   myList.sort();
   myList2.sort();
   cout << "Список: ";
    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));
    cout << endl;
       cout << "Список2: ";
   copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout," "));
    cout << endl;

    myList.merge(myList2);
   cout << "Список: ";
   copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));
cout << endl;

   myList.unique();
   cout << "Список1 merge: ";
   copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));
   cout << endl;

   cout << "Список2: ";
   copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout," "));

   return 0;
}
