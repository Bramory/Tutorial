#include <iostream>
#include <fstream>
#include <iterator>//for use ostream_iterator
#include <algorithm>//for sort() function
#include <map>//asociated arrays
#include <string>
using namespace std;
int main(){

vector<int> vec1(5);

  vec1.push_back(1);
  vec1.push_back(1);
  vec1.push_back(1);


  cout << endl;
  cout << "capacity before = " << vec1.capacity()<< "\n";

  vec1.shrink_to_fit();

  cout << endl;
  cout << "capacity after shrink = " << vec1.capacity() << "\n";
  int a = vec1[6];
  vec1.push_back(1);
  vec1.push_back(1);


  cout << endl;
  cout << "capacity add 2 elem = " << vec1.capacity() << "\n";

  vec1.shrink_to_fit();

  cout << endl;
  cout << "capacity after shrink = " << vec1.capacity() << "\n";
}
