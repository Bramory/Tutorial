#include <iostream>
#include <map>
using namespace std;

int main()
{
  map <string,int> myMap = {{ "Beta", 2 }, ///����� ������������� map
                            { "Alpha", 1 },
                            { "Gamma", 3 }};

  ///���������� ��������� map ����� ��������
   myMap.at("Beta") = 0;
   myMap.at("Alpha") = 233;
   myMap.at("Gamma") = -45;

  cout << "myMap contains:\n";
  for(auto it = myMap.begin(); it != myMap.end(); ++it)
  {
      cout << it->first << " : " << it->second << endl;///����� �� �����
  }

  multimap <char,int> myMultimap;///�������� multimap

   ///��������� myMultimap
   myMultimap.insert ( pair<char,int>('q',111) );
   myMultimap.insert ( pair<char,int>('u',201) );
   myMultimap.insert ( pair<char,int>('h',301) );

   cout << "\nmyMultimap contains:\n";
   for (auto it = myMultimap.begin(); it != myMultimap.end(); ++it)
   {
      cout << it->first << " : " << it->second << endl;
   }

   myMap.clear();
   myMultimap.clear();

   ///����� ������������� myMap
   myMap = {{ "Mike", 40 },
            { "Walle", 999 },
            { "Cloude", 17 }};

   ///����� ������������� myMultimap
   myMultimap.insert ( pair<char,int>('q',222) );
   myMultimap.insert ( pair<char,int>('u',223) );
   myMultimap.insert ( pair<char,int>('h',221) );

   auto itMap = myMap.begin();///������� �������� �� ������ my�ap
   auto itMultimap = myMultimap.begin();///������� �������� �� ������ myMultimap
   cout << "\nmyMap after clear contains: \t myMultimap after clear contains:\n";

   ///����� �� ����� myMap � myMultimap
   for(itMap = myMap.begin(),itMultimap = myMultimap.begin(); itMultimap != myMultimap.end(); itMap++,itMultimap++)
   {
       cout << "\t" <<itMap->first << " : " << itMap->second << "\t\t\t\t" << itMultimap->first << " : " << itMultimap->second << endl;
   }
   return 0;
}
