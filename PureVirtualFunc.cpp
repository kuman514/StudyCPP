#include <iostream>

class Parent
{
    public:
        virtual void print(int) = 0;
        // Pure Virtual Function
        // Stating "= 0" after the function is required.
        /*
           This is like...
           void *FuncPtr(int) = NULL;
           in C Programming
        */
};

class Child : public Parent
{
    public:
        virtual void print(int a = 514)
        {
            std::cout << "Koishi!" << ' ' << a << std::endl;
        }
        // You have to state the detail of the pure virtual function in inherited classes.
};

int main(void)
{
    Child k;
    k.print();
    k.print(12);
    return 0;
}
