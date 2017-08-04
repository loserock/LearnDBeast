#include <iostream>
#include <typeinfo>

int* fv(int i = 0)
{
    return new int(i);
}

int& fvr(int i = 0)
{
    int * j = new int(i);
    return *j;
}

int main()
{
    auto i = fv(1);
    std::cout << i << " " << typeid(i).name() << std::endl;
    auto j = fvr(*i + 1);
    std::cout << j << " " << typeid(j).name() << std::endl;
    return 0;
}