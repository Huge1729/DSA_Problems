#include <iostream>
using namespace std;

class A {
private:
    int *a;

public:
    // Constructor
    A(int x) {
        a = new int(x); // Dynamically allocate memory
    }

    // Copy Constructor (Shallow Copy)
    A(const A &obj) {
        a = obj.a; // Copy the pointer (shallow copy)
    }
    
    // Copy Constructor (Deep Copy)
    // A(const A &obj) {
    //     a = new int(*obj.a); // Allocate new memory and copy the value pointed to by obj.a
    // }

    // Set Data
    void setData(int x) {
        *a = x;
    }

    // Display Data
    void getData() const {
        cout << *a << endl;
    }

    ~A() {
        delete a; // Clean up dynamically allocated memory
    }
};

int main() {
    A obj1(5);
    obj1.getData();  // Output: 5

    A obj2(obj1);    // Shallow copy, obj2.a points to the same memory as obj1.a
    obj2.getData();  // Output: 5

    obj2.setData(10); // Modify obj2, affects obj1 as well because they share the same memory
    obj2.getData();  // Output: 10
    obj1.getData();  // Output: 10 (Note: obj1 also shows 10)

    return 0;
}
