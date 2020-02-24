#include <iostream>
#include <cstdio>
#include <vector>
#include "../include/linked_list.h"
// #include "../include/node.h"

using namespace std;
typedef linked_list<int> ll_int;

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


class B{
    int a;
    int b;
    public:
    explicit B(int x){
        a = x;
        b = x *10;
    }
    int get(){return b;}

};

void f(B b){
    cout<<b.get()<<endl;
}

int main()
{   
    // node<int> a = node<int>(5);
    // std::cout << a.value << std::endl;
    ll_int l;
    std::cout << l.Length() << std::endl;
    l.add_last(0);
    l.at(0) = 6;
    ll_int l1(l);
    std::cout << l.Length() << std::endl;
    std::cout << l[0] << std::endl;



    for(int i = 1; i < 10; i++)
    {
        l.add_last(i);
    }
    std::cout << l.Length() << std::endl;

    ll_int l2 = l(0, 4);
    l2[3] = 5;
    std::cout << l2[3] << std::endl;

    f( (B)10);

    return 0;
}