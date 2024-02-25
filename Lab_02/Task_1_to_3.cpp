#include <iostream>
using namespace std;

// Abstract class
class Animal
{
public:
    virtual void make_sound() = 0; // Pure virtual function
};

// Derived classes
class Lion : public Animal
{
public:
    void make_sound() override
    {
        cout << "The loin Roar" << endl;
    }
};
// Derived classes
class Elephant : public Animal
{
public:
    void make_sound() override
    {
        cout << "The Elephant says Trumpet" << endl;
    }
};
// Derived classes
class Monkey : public Animal
{
public:
    void make_sound() override
    {
        cout << "The monkey says Ooh ooh aah aah" << endl;
    }
};
// Derived classes
class Bird : public Animal
{
public:
    void make_sound() override
    {
        cout << "The bird says Chirp chirp" << endl;
    }
};

// Derived classes
class Jibran : public Animal   //just for fun haha
{
public:
    void make_sound() override
    {
        cout << "Jibran: Yooooooo" << endl;
    }
};
// Function demonstrating polymorphism
void hear_sound(Animal& animal)
{
    animal.make_sound();
}

int main()
{
    Lion lion;
    Elephant elephant;
    Monkey monkey;
    Bird bird;
    Jibran mj;

    hear_sound(lion);
    hear_sound(elephant);
    hear_sound(monkey);
    hear_sound(bird); 
    hear_sound(mj);  //noob boy
    return 0;
}
