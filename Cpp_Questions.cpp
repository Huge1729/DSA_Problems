#include <iostream>

// union u {
//     struct st {
//         int i : 7;  // 7-bit field
//         int j : 7;  // 7-bit field
//         int k : 7;  // 7-bit field
//         int l : 7;  // 7-bit field
//     } st;
//     int i;
// };

// int main() {
//     u myUnion;
//     myUnion.i = 100; // Assigning 100 to the union's integer

//     std::cout << "Union integer value: " << myUnion.i << std::endl;
//     std::cout << "Structure fields: " << myUnion.st.i << " " << myUnion.st.j << " " << myUnion.st.k << " " << myUnion.st.l << std::endl;

//     return 0;
// }

// int main() {
//     enum e1 { m1, m2, m3, m4 };
//     enum e2 { mem1 = -1, mem2, mem3, mem4 };
//     enum e3 { member1, member2, member3, member4 = 10 };

//     printf("%d %d %d", m3, mem3, member3);
// }


// #include <stdio.h>

// int main() {
//     char a[10] = "\\0\0\2bc";  // Initializing a char array with a string
//     int i = 0;

//     while (i < 3) {
//         switch (a[i++]) {  // Switch based on the current character and then increment i

//             case '\\':  // Case when the character is '\\'
//                 printf("This question is good\n");
//                 break;

//             case 0:  // Case when the character is the null character '\0'
//                 printf("This question is too good\n");
//                 break;

//             default:  // Default case for any other character
//                 printf("Predict the output\n");
//                 break;
//         }
//     }

//     return 0;
// }




// #include <stdio.h>

// int main() {
//     float f = 1.0;

//     switch (f) {
//         case 1.0:
//             printf("One ");
//         case 2.0:
//             printf("Two ");
//             break;
//         case 3.0:
//             printf("Three ");
//             break;

//     }
//     printf("Main");
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int i = 0;        // Declare and initialize an integer
//     int &r = i;       // Declare a reference to i
//     int *p = &i;      // Declare a pointer pointing to i

//     i++;              // Increment i
//     r++;              // Increment i through the reference
//     (*p)++;           // Increment i through the pointer

//     cout << *p << endl; // Print the value of i through the pointer
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class A {
// public:
//     int i = 7;
    
//     // Declare the pure virtual function (abstract method in C#)
//     virtual void display() = 0; 
// };

// class B : public A {
// public:
//     int j;

//     // Override the pure virtual function
//     void display() override {
//         cout << i << endl;
//         cout << j << endl;
//     }
// };

// int main() {
//     B obj;       // Create an object of class B
//     A* obj1 = &obj;  // Use A pointer to refer to object of class B
    
//     obj.j = 1;    // Set value of j
//     obj1->i = 8;    // Set value of i

//     obj.display();  // Call display method using object of B
//     obj1->display(); // Call display method using A pointer

//     return 0;
// }


#include <iostream>
using namespace std;

#define NAME_SIZE 50

class Person {
    int id;
    char name[NAME_SIZE];

public:
    void aboutme() { // Use 'virtual' for polymorphism
        cout << "I am a person." << endl;
    }
   // virtual ~Person() {} // Virtual destructor for proper cleanup 
};

class Student : public Person {
public:
    void aboutme() { 
        cout << "I am a student." << endl;
    }
};

int main() {
    Person* p = new Student(); // Base class pointer to derived class object
    p->aboutme();              // Calls the overridden method in Student
    delete p;                  // Proper cleanup
    return 0;
}
