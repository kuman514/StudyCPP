#include <iostream>
#include <typeinfo>
using namespace std;
int main(void)
{
    int a(5);
    int b = 5;
    int c = {5};
    int d{5};
    char e = 'f';

    cout << a << b << c << d << e << endl;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(e).name() << endl;

    return 0;
}
