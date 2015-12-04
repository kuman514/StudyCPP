#include <iostream>

namespace first
{
    void hungry(void)
    {
        std::cout << "hungry first" << std::endl;
    }

    void printNum(int pr)
    {
        std::cout << "first : " << pr << std::endl;
    }
};

namespace second
{
    void hungry(void)
    {
        std::cout << "hungry second" << std::endl;
    }

    void printNum(int pr)
    {
        std::cout << "second : " << pr << std::endl;
    }
};

int main(void)
{
    first::hungry();
    second::hungry();
    first::printNum(10);
    second::printNum(20);
    return 0;
}
