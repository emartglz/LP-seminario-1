#include <iostream>
#include <cstdio>
#include "../include/linked_list.h"

//esto lo estoy usando para testear cosas durante la implementacion
struct A {
    int a;

    A(int v) : a(v) {
        std::cout << "contructor" << std::endl;
    }

    A(int &v) : a(v) {
        std::cout << "constructor 2" << std::endl;
    }

    A() : a(0) {
        std::cout << "default constructor" << std::endl;
    }

    A(A &a) : a(a.a) {
        std::cout << "copy constructor lvalue" << std::endl;
    }

    A(A &&a) : a(a.a) {
        std::cout << "copy constructor rvalue" << std::endl;
    }

    void operator=(A &&a) {
        this->a = a.a;
        std::cout << "operator= overload rvalue" << std::endl;
    }

    void operator=(A &a) {
        this->a = a.a;
        std::cout << "operator= overload lvalue" << std::endl;
    }

    ~A() {
        std::cout << "destructor" << std::endl;
    }
};

int main()
{   
    linked_list<int> l;
    std::cout << l.Length() << std::endl;
    l.add_last(0);
    std::cout << l.Length() << std::endl;
    std::cout << l.at(0) << std::endl;

    for(int i = 1; i < 10; i++)
    {
        l.add_last(i);
    }
    std::cout << l.Length() << std::endl;

    linked_list<int> l2 = l(0, 4);
    l2[3] = 5;
    std::cout << l2[3] << std::endl;
    return 0;
}