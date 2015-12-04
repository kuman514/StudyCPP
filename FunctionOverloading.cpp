#include <iostream>

void printSum(int, int);
void printSum(double, double);

int main(void)
{
    printSum(1,2);
    printSum(30.3,2.2);
    return 0;
}

void printSum(int pr1, int pr2)
{
    std::cout << pr1 + pr2 << std::endl;
}

void printSum(double pr1, double pr2)
{
    std::cout << pr1 + pr2 << std::endl;
}
