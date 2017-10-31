#include <iostream>
#include <map>

using namespace std;
int main ()
{
  multimap<float,string> myMultimapExample;
  map<string,float> myMapExample;

  /// первый вариант
  myMapExample.insert ( pair<string,float>("Desk",0.01) );
  myMapExample.insert ( pair<string,float>("Table",0.02) );
  myMultimapExample.insert ( pair<float,string>(0.01,"Desk") );
  myMultimapExample.insert ( pair<float,string>(0.01,"Table") );

  /// второй вариант
  multimap<float,string>::iterator itMultimapExample = myMultimapExample.begin();///итератор указывает на начало multimap
  map<string,float>::iterator itMapExample = myMapExample.begin();
  myMapExample.insert ( itMapExample, pair<string,float>("Pencil",0.03) );
  myMultimapExample.insert ( itMultimapExample, pair<float,string>(0.03,"Pencil") );

  /// третий вариант
  map<string,float> myMapExampleDifferent;
  multimap<float,string> myMultimapExampleDifferent;
  myMapExampleDifferent.insert( myMapExample.begin(),myMapExample.find("Table") );
  myMultimapExampleDifferent.insert( myMultimapExample.begin(),myMultimapExample.find(0.03) );

  /// вывод на экран map и multimap:
  cout << "myMapExample: \t\t myMultimapExample:\n";
  for ( itMapExample = myMapExample.begin(),itMultimapExample = myMultimapExample.begin(); itMapExample != myMapExample.end(); ++itMapExample,++itMultimapExample)
  {
      cout << itMapExample->first << " : " << itMapExample->second << "\t\t   " << itMultimapExample->first << " : " << itMultimapExample->second << endl;
  }

  auto itMapExampleDif = myMapExampleDifferent.begin();
  auto itMultimapExampleDif = myMultimapExampleDifferent.begin();
  cout << "\nmyMapExampleDifferent: \t myMultimapExampleDifferent:\n";
  for ( itMapExampleDif,itMultimapExampleDif; itMapExampleDif != myMapExampleDifferent.end(); ++itMapExampleDif,++itMultimapExampleDif)
  {
      cout << itMapExampleDif->first << " : " << itMapExampleDif->second << "\t\t    " << itMultimapExampleDif->first << " : " << itMultimapExampleDif->second << '\n';
  }

  return 0;
}
