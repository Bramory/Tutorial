#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ctime>
#include <string>
#include <list>
#include <assert.h>
#include "tools.h"

using namespace std;


typedef pair <char, int> Card;
/// methods for comparing
/// pointer on fuction
bool func_cmp(list<Card>::reference lt, list<Card>::reference rt) {
    int valLt =  lt.first  * 13 + lt.second;
    int valRt =  rt.first  * 13 + rt.second;
    return valLt < valRt;
}

///functional object
class my_cmp{
public:
    bool operator () (list<Card>::reference lt, list<Card>::reference rt) {
        int valLt =  lt.first  * 13 + lt.second;
        int valRt =  rt.first  * 13 + rt.second;
        return valLt < valRt;
    }
} obj_cmp;

void takeCard(stack <Card> deck, list<Card> &p_list){
    Card newCard = deck.top();
    cout << "\n\nCard:" <<  newCard.first << newCard.second << endl;

    list<Card>::iterator it = p_list.begin();
    while(it != p_list.end() ){
        if(it->first * 13 + it->second < newCard.first * 13 + newCard.second )
            it++;
        else
            break;
    }
    p_list.emplace(it, newCard);
}

void show_cards(list <Card> cards){
    for(auto it = cards.begin(); it != cards.end(); it++){
        cout << it->first; ///suit

        if (it->second >= 11 ){
            char tmp = '\0';
            switch(it->second){
                case 11: tmp = 'J';
                break;
                case 12: tmp = 'Q';
                break;
                case 13: tmp = 'K';
                break;
                case 14: tmp = 'A';
                break;
            }
            cout << tmp;
        }
        else
            cout << it->second; ///number

        if(it != --cards.end() )
        cout << ", "; ///without last ','
    }
}

int main(){
    srand(time(0));
    const int N = 36;
    vector <Card> deck_v;
    deck_v.reserve(N+16);

    cout << "CAPACITY = " << deck_v.capacity() << endl;
    cout << "SIZE = " << deck_v.size() << endl;

    ///fill deck of cards
    for(char i = 3; i < 7; i++){ ///suit on ASCII
        for(int j = 2; j < 15; j++){
            deck_v.push_back( make_pair(i, j) );
        }
    }

    ///shuffle deck of cards
    for(size_t i = 0; i < deck_v.size(); i++){
        int in = randFromRange<int>( 0, deck_v.size()-1);
        swap(deck_v[i], deck_v[in] );
    }

    /// vector -> stack
    stack <Card> deck_s;
    for(size_t i = 0; i < deck_v.size(); i++){
        deck_s.push( make_pair(deck_v[i].first, deck_v[i].second));
//        cout << i << ") "
//        << deck_v[i].first
//        << deck_v[i].second
//        ///<< deck_v[i].getSuit()  * 13 + deck_v[i].getRang()
//        << endl;
    }
    ///destruct vector
    deck_v.clear();
    deck_v.shrink_to_fit();
    cout << "STACK SIZE = " << deck_s.size() << endl;

///     player get 6 cards from the deck
    list <Card> p_list;
    for(int i = 0; i < 6; i++){
        p_list.push_back( make_pair(deck_s.top().first, deck_s.top().second) );
        deck_s.pop();
    }
    cout << endl;


    cout << "before:\n";
    show_cards(p_list);

    try{
        p_list.sort( obj_cmp ); /// or func_cmp
        throw -1;
    }
    catch(...){
        cout << "EXCEPTION FOUND!";
    }

    cout << "\nafter:" << endl;
    show_cards(p_list);
    takeCard(deck_s, p_list); ///insert in right order


    cout << endl << "Player 1 have(after):" << endl;
    show_cards(p_list);

    system("pause");
    return 0;
}
