#include <iostream>
#include <map>
using namespace std;

int main()
{
  multimap <char,int> myMultimap;
  map <char,int> myMap;
  char c;
  for (int i = 0,c = 'a'; i < 5; ++i,++c)
  {
      myMap[c] = i;///��������� map
  }

   ///��������� multimap
   myMultimap.insert ( pair<char,int>('c',146) );
   myMultimap.insert ( pair<char,int>('a',23) );
   myMultimap.insert ( pair<char,int>('b',996) );
   myMultimap.insert ( pair<char,int>('a',56) );
   myMultimap.insert ( pair<char,int>('c',121) );
   auto itMap = myMap.begin();///������� �������� �� ������ my�ap
   auto itMultimap = myMultimap.begin();///������� �������� �� ������ myMultimap
   cout<<"myMap contains: \t myMultimap contains:\n";

   ///����� �� ����� myMap � myMultimap
   for(itMap = myMap.begin(),itMultimap = myMultimap.begin(); itMultimap != myMultimap.end(); itMap++,itMultimap++)
   {
       cout << itMap->first << " : " << itMap->second << "\t\t\t\t" << itMultimap->first << " : " << itMultimap->second << endl;
   }

   for(c = 'a'; c <= 'f'; c++)
   {
      myMap.count(c) ? cout << "\nNumber of elements '" << c << "' in myMap = " << myMap.count(c) : cout << "\nElement '" << c << "' is not in myMap ";
      myMultimap.count(c) ? cout << "\nNumber of elements '" << c << "' in myMultimap " << myMultimap.count(c) : cout << "\nElement '" << c << "' is not in myMultimap";
   }

   itMap = myMap.find('b');///�������� �� �������� ������� � map
   itMultimap = myMultimap.find('a');///�������� �� �������� ������� � multimap
   myMap.erase(itMap);///������� ��� � map
   myMultimap.erase(itMultimap);///������� ��� � multimap
   itMap = myMap.find('d');
   itMultimap = myMultimap.find('d');
   myMap.erase(itMap,myMap.end());///������� c �������� 'd' � �� ����� map
   myMultimap.erase(itMultimap,myMultimap.end());///������� c �������� 'd' � �� ����� multimap

   cout << "\n\nmyMap contains: \t myMultimap contains:\n";
   ///int i; �� ��� �������� �������� �� �����
   for(itMap = myMap.begin(),itMultimap = myMultimap.begin(); itMap != myMap.end(); itMap++,itMultimap++)
   {
      cout << itMap->first << " : " << itMap->second << "\t\t\t\t" << itMultimap->first << " : " << itMultimap->second << endl;///����� �� �����
   }

   myMap.clear();
   myMap.empty() ? cout << "\nmyMap is empty\n" : cout << "myMap isn't empty\n";
   myMultimap.empty() ? cout << "\nmyMultimap is empty\n" : cout << "myMultimap isn't empty\n";

   return 0;
}
