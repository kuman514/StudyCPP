#include <iostream>

class Parent
{
    public:
        Parent() { std::cout << "Parent Create : " << this << std::endl; }
        virtual ~Parent() { std::cout << "Parent Perish : " << this << std::endl; }
        virtual void print(void) { std::cout << "Parent Print : " << this << std::endl; }
};

class Child : public Parent
{
    public:
        Child() { std::cout << "Child Create : " << this << std::endl; }
        virtual ~Child() { std::cout << "Child Perish : " << this << std::endl; }
        virtual void print(void) { std::cout << "Child Print : " << this << std::endl; }
};

int main(void)
{
    Parent *test0 = new Parent;
    Parent *test1 = new Child;
    Child *test2 = new Child;
    Child test3;
    // According to the result, inherited classes create its parent first.

    test0 -> print();
    test1 -> print();
    test2 -> print();
    test3.print();
    
    test1 -> Parent::print();
    
    delete test0;
    delete test1;
    delete test2;
    
    //Create
    //
    //Parent
    //  - Child

    //Perish
    //
    //  - Child
    //Parent
    
    return 0;
}
