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


// #include <iostream>
// using namespace std;

// #define NAME_SIZE 50

// class Person {
//     int id;
//     char name[NAME_SIZE];

// public:
//     void aboutme() { // Use 'virtual' for polymorphism
//         cout << "I am a person." << endl;
//     }
//    // virtual ~Person() {} // Virtual destructor for proper cleanup 
// };

// class Student : public Person {
// public:
//     void aboutme() { 
//         cout << "I am a student." << endl;
//     }
// };

// int main() {
//     Person* p = new Student(); // Base class pointer to derived class object
//     p->aboutme();              // Calls the overridden method in Student
//     delete p;                  // Proper cleanup
//     return 0;
// }




// #include <iostream>

// using namespace std;

// class Test {

// public:

//     Test(Test &t) {}

//     Test() {}

// };

// Test fun() {

//     cout << "fun() Called\n";

//     Test t;

//     return t;

// }

// int main() {

//     Test t1;

//     Test t2 = fun();

//     return 0;

// }


// #include <iostream>

// using namespace std;

// class Abc {
// public:
//     Abc(int aa0): a(aa0) {}  // Corrected this line

//     void show() { cout << "a = " << a << endl; }

// private:
//     int a;
// };

// class Xyz {
// public:
//     Xyz(int xx): x(xx) {}

//     operator Abc() const { return Abc(x); }

// private:
//     int x;
// };

// void g(Abc abc) { abc.show(); }

// int main() {
//     Xyz xyz(10);
//     g(xyz);  // Will convert xyz to Abc, showing "a = 10"
//     g(20);   // Will call Abc constructor directly with 20, showing "a = 20"
//     return 0;
// }



// #include <stdio.h>

// enum OSState { Running = 1, Terminated = 0, Failed = 0};

// int main() {
//     printf("%d, %d %d", Running, Terminated, Failed);
//     return 0;
// }


#include <iostream>

void MyFunction(int a, int b = 40)
{
    std::cout << "a = " << a << " b = " << b << std::endl;
}

int main()
{
    MyFunction(20);
    return 0;
}
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


// #include <iostream>
// using namespace std;

// #define NAME_SIZE 50

// class Person {
//     int id;
//     char name[NAME_SIZE];

// public:
//     void aboutme() { // Use 'virtual' for polymorphism
//         cout << "I am a person." << endl;
//     }
//   // virtual ~Person() {} // Virtual destructor for proper cleanup 
// };

// class Student : public Person {
// public:
//     void aboutme() { 
//         cout << "I am a student." << endl;
//     }
// };

// int main() {
//     Person* p = new Student(); // Base class pointer to derived class object
//     p->aboutme();              // Calls the overridden method in Student
//     delete p;                  // Proper cleanup
//     return 0;
// }

// #include <iostream>

// using namespace std;

// class Test {

// public:

//     Test(Test &t) {}

//     Test() {}

// };

// Test fun() {

//     cout << "fun() Called\n";

//     Test t;

//     return t;

// }

// int main() {

//     Test t1;

//     Test t2 = fun();

//     return 0;

// }


// #include <iostream>

// using namespace std;

// class Abc {
// public:
//     Abc(int aa0): a(aa0) {}  // Corrected this line

//     void show() { cout << "a = " << a << endl; }

// private:
//     int a;
// };

// class Xyz {
// public:
//     Xyz(int xx): x(xx) {}

//     operator Abc() const { return Abc(x); }

// private:
//     int x;
// };

// void g(Abc abc) { abc.show(); }

// int main() {
//     Xyz xyz(10);
//     g(xyz);  // Will convert xyz to Abc, showing "a = 10"
//     g(20);   // Will call Abc constructor directly with 20, showing "a = 20"
//     return 0;
// }



// #include <stdio.h>

// enum OSState { Running = 1, Terminated = 0, Failed = 0};

// int main() {
//     printf("%d, %d %d", Running, Terminated, Failed);
//     return 0;
// }


#include <iostream>

void MyFunction(int a, int b = 40)
{
    std::cout << "a = " << a << " b = " << b << std::endl;
}

int main()
{
    MyFunction(20);
    return 0;
}


// #include <iostream>
// using namespace std;

// union Data {
//     int i;
//     float f;
//     char c;
//     int j;
// };

// int main() {
//     Data data;

//     data.i = 42; // Write to the integer member
//     cout << "Accessing `i`: " << data.i << endl;

//     // Accessing a different member (float) without writing to it
//     cout << "Accessing `f` (undefined behavior): " << data.f << endl;
//     cout << "Accessing `c` (undefined behavior): " << data.c << endl;
//     cout << "Accessing `i`: " << data.j << endl;
    
    
//     data.c = 'A'; // Write to the char member
//     cout << "Accessing `c`: " << data.c << endl;

//     // Accessing `i` after writing to `c` (undefined behavior)
//     cout << "Accessing `i` again (undefined behavior): " << data.i << endl;

//     return 0;
// }



// enum color{
//     red, green, yellow
// };

// int main() {
//     color c;
//     cout<<red<<endl;
//     return 0;
// }


// #include <iostream>
// using namespace std;

// struct Empty {};

// int main() {
//     Empty e1, e2;
//     cout << "Size of empty structure: " << sizeof(Empty) << " byte" << endl;
//     cout << "Address of e1: " << &e1 << endl;
//     cout << "Address of e1: " << sizeof(&e1) << endl;
//     cout << "Address of e2: " << &e2 << endl;
//     return 0;
// }


// #include<stdio.h>
// int main()
// {
//     int arr[] = {10, 20, 30, 40, 50, 60};
//     int *ptr1 = arr;
//     int *ptr2 = arr + 5;
//     printf("Number of elements between two pointer are: %d.", 
//                                 (ptr2 - ptr1));
//     printf("Number of bytes between two pointers are: %d",  
//                               (char*)ptr2 - (char*) ptr1);
//     return 0;
// }

// #include <stdio.h>

// void fun(int **p) {  // Here, we take a pointer to the pointer.
//     int q = 10;
//     *p = &q;  // This modifies the original pointer p in main.
// }

// int main() {
//     int r = 20;
//     int *p = &r;  // p points to r.
//     fun(&p);  // Pass the address of p (pointer to pointer).
//     printf("%d", *p);  // This will print the value at *p, which is now pointing to q.
//     return 0;
// }



#include <stdio.h>

void fun(int *p) {
    *p = 10;  // Modify the value that p points to
}

int main() {
    int r = 20;
    int *p = &r;  // p points to r
    fun(p);  // Pass p (pointer to r) to fun
    printf("%d", r);  // Prints the new value of r, which should be 10
    return 0;
}




