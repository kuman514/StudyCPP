#include <iostream>

using std::cout;
using std::endl;

namespace test
{
    void printNum(int pr)
    {
        cout << pr << endl;
    }
}

int main(void)
{
    test::printNum(10);
    return 0;
}
