#include <iostream>

class Minus
{
    public:
        Minus(int num = 0) : num(num) {};
        ~Minus() {};
        int operator+(Minus m);
        int operator-(Minus m);
    private:
        int num;
};

int Minus::operator+(Minus m)
{
    return (this -> num) - (m.num);
}

int Minus::operator-(Minus m)
{
    return (this -> num) + (m.num);
}

int main(void)
{
    Minus a(20);
    Minus b(10);
    std::cout << a + b << ' ' << a - b << std::endl;
    return 0;
}
