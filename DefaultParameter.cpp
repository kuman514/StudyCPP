#include <iostream>
using namespace std;

void printNum(int num = 7);
void printNums(int num1, int num2 = 10, int num3 = 30);

int main(void)
{
    printNum(5);
    printNum();
    printNums(5);
    return 0;
}

void printNum(int num)
{
    cout << "num : " << num << endl;
}

void printNums(int num1, int num2, int num3)
{
    cout << "num1 : " << num1 << endl;
    cout << "num2 : " << num2 << endl;
    cout << "num3 : " << num3 << endl;
}
