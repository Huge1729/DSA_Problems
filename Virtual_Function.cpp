#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Overriding the sound function
    void sound() {
        cout << "Dog barks" << endl;
    }
};

// Another Derived class
class Cat : public Animal {
public:
    // Overriding the sound function
    void sound() {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal *animalPtr;

    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->sound(); // Outputs: Dog barks (Dog's version of sound())

    animalPtr = &cat;
    animalPtr->sound(); // Outputs: Cat meows (Cat's version of sound())

    return 0;
}
