#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ctime>
#include <string>
#include <list>
using namespace std;

//return element from [a ... b]
//template <typename T>
int randFromRange (int min, int max){
    return rand() % (max-min+1) + min;
}

//template <typename T>
class Card{
    int rang;
    char suit;
public:
    Card(){}
    ~Card(){}
    inline int getRang(void){ return rang; }
    inline char getSuit(void)const{ return suit;}
    inline void setRang(int r){ rang = r;}
    inline void setSuit(char m){ suit = m;}

//    Card operator = ( Card rCard){
//        Card aCard;
//        aCard.setRang(rCard.getRang());
//        aCard.setSuit(rCard.getSuit());
//        return aCard;
//    }

    ostream & operator << (ostream &s){
        //        switch(rang)){
//            case 11: tmp_rang = "J";
//            break;
//            case 12: tmp_rang = "Q";
//            break;
//            case 13: tmp_rang = "K";
//            break;
//            case 14: tmp_rang = "A";
//            break;
//            default: tmp_rang = rang + 48;
//            break;
//    }
        return (s << this->getSuit() << "," << this->getRang() );
    }

};

// methods for comparing
// pointer on fuction
bool func_cmp(Card lt, Card rt) {
    int valLeft =  lt.getSuit()  * 13 + lt.getRang();
    int valRight = rt.getSuit()  * 13 + rt.getRang();
    return (valLeft < valRight);
}

//functional object
class my_cmp{
public:
    bool operator () (Card lt, Card rt) {
        int valLeft =  lt.getSuit()  * 13 + lt.getRang();
        int valRight = rt.getSuit()  * 13 + rt.getRang();
        return (valLeft < valRight);
    }
} obj_cmp;


void show_cards(list<Card> cards){
    for(auto i = cards.begin(); i != cards.end(); i++){
        cout << i->getSuit() << i->getRang();
        if(i != cards.end() ) // ?
        cout << ", ";
    }
}

int main(){
    srand(time(0));
    const int N = 36;
    vector <Card> deck_v;
    deck_v.reserve(N+16);

    cout << "CAPACITY = " << deck_v.capacity() << endl;
    cout << "SIZE = " << deck_v.size() << endl;

    //fill deck of cards
    for(int i = 3; i < 7; i++){ //suit
        for(int j = 2; j < 15; j++){
            Card newCard;
            newCard.setSuit(i);
            newCard.setRang(j); //48
//            cout << i << " ";
//            cout << j << endl;
            deck_v.push_back(newCard);
        }
    }

    //shuffle deck of cards
    for(size_t i = 0; i < deck_v.size(); i++){
        int in = randFromRange(0, deck_v.size()-1);
        swap(deck_v[i], deck_v[in] );
    }

    stack <Card> deck_s;
    for(size_t i = 0; i < deck_v.size(); i++){
        deck_s.push(deck_v[i]);
        cout << i << ") "
        << deck_v[i].getSuit()
        << deck_v[i].getRang()
        //<< deck_v[i].getSuit()  * 13 + deck_v[i].getRang()
        << endl;
    }
    //destruct vector
    deck_v.clear();
    deck_v.shrink_to_fit();
    cout << "STACK SIZE = " << deck_s.size() << endl;

    // player get the cards from the deck
    list <Card> cards1;
    for(int i = 0; i < 6; i++){
        cards1.push_back( deck_s.top() );
        deck_s.pop();
    }
    cout << endl;

    cout << "Player 1 have(before):" << endl;
    show_cards(cards1);

    cards1.sort( obj_cmp ); //func_cmo

    cout << endl << "Player 1 have(after):" << endl;
    show_cards(cards1);

    list <pair <int, char>> pl;
    pl.emplace_front(1, 'a');
    pl.emplace_front(2, 'b');
    for(auto& it: pl){
      cout << it.first  << it.second << ", ";
    }


//     player get the cards from the deck
//    list <Card> cards2;
//    for(int i = 0; !deck_s.empty(); i++){
//        cards2.push_back( deck_s.top() );
//        deck_s.pop();
//    }
//    cout << endl;
//    show_cards(cards2);

//    cout << "Stack s1: " << endl;
//    for(auto newCard = deck_s.top(); !deck_s.empty(); deck_s.pop()){
//            newCard = newCard + 1;
//        cout << newCard.getSuit() << " " << newCard.getRang() << endl;
//    }

    system("pause");
    return 0;
}
