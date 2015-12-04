#include <iostream>
#include <typeinfo>

void checkRef(int &pr);
void checkConstRef(const int &pr);
int& checkReturnRef(int &pr);

int main(void)
{
    int variable = 10;
    int return_value;

    std::cout << "main : " << variable << std::endl;
    std::cout << "main : " << &variable << std::endl;
    checkRef(variable);
    checkConstRef(variable);

    return_value = checkReturnRef(variable);
    std::cout << "return reference : " << return_value << std::endl;
    int &return_value_ref = checkReturnRef(variable);
    std::cout << "return reference : " << &return_value_ref << std::endl;
    return 0;
}

void checkRef(int &pr)
{
    std::cout << "checkref : " << pr << std::endl;
    std::cout << "checkref : " << pr << std::endl;
}

void checkConstRef(const int &pr)
{
    std::cout << "checkconstref : " << typeid(pr).name() << std::endl;
}

int& checkReturnRef(int &pr)
{
    return pr;
}
