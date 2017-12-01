#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

void mergeSort(vector <int>&a, size_t start, size_t end){
    //arr have 1 or 0 element -> stop sort
    if(end-start < 2)
        return;
    ///arr have 2 -> sort them
    if(end-start == 2){
        if(a[start] > a[start+1])
            swap(a[start], a[start+1]);
        return;
    }

    mergeSort(a, start, start + (end-start)/2);
    mergeSort(a, start + (end-start)/2, end);

    size_t b1 = start;
    size_t e1 = start + (end-start)/2;
    size_t b2 = e1;
    vector <int> b;
    while(b.size() < end-start){
        if(b1 >= e1 || (b2 < end && a[b1] >= a[b2])){
            b.push_back(a[b2]);
            b2++;
        }
        else{
            b.push_back(a[b1]);
            b1++;
        }
    }
    for(size_t i = start; i < end; i++)
        a[i] =  b[i-start];
}

int main(){
    srand(time(0));
    vector <int> v;
    size_t N = 30;

    for(int i = 0; i < N; i ++)
        v.push_back(rand() % N);

    for(int i = 0; i < N; i ++)
        swap(v[i], v[rand() % v.size()]);

    for(int i = 0; i < N; i ++)
        cout << v[i] << " ";
    cout << endl;

    mergeSort(v, 0, v.size());

    for(int i = 0; i < N; i ++)
        cout << v[i] << " ";
    cout << endl;


return 0;
}
