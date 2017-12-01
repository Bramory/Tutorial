#include <iostream>
#include <cstring>
using namespace std;
class Animal
{
    int age;
    float weight;
    public:
    virtual ~Animal() {}
    virtual void speak() {
    cout << "I'm animal!" << endl;
    }
};

class Dog : public Animal{
    char *breed;
    public:
    Dog(char * b) {
    breed = new char [strlen(b) + 1];
    strcpy(breed, b);
    }
    virtual ~Dog() { delete [] breed; }
    virtual void speak() {
        cout << "I'm dog and I'm " << breed << endl;
    }
};

class Cat : public Animal
{
    char *color;
    public:
    Cat(char *c) {
        color = new char [strlen(c) + 1];
        strcpy(color, c);
    }
    virtual ~Cat() { delete [] color; }
    virtual void speak() {
        cout << "I'm cat and I'm " << color << endl;
    }
};
int main(){
    Animal*p_a[3];
    Animal a;
    Cat c("white");
//    c.~Cat();   /// first uncomment
    Dog d("Doberman");
//    Cat c2("Red"); /// second uncomment
    c.speak(); // WTF Windows is doing!

//    p_a[0] = &a;// Вказівник об’єкту базового класу Animal
//    p_a[1] = &c;// Вказівник об’єкту похідного класу Cat
//    p_a[2] = &d;// Вказівник об’єкту похідного класу Dog
//    for (int i = 0; i < 3; i++) {
//        p_a[i]->speak();
//    }
return 0;
}
