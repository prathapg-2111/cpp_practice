#include <iostream>

int main()
{
    auto fn = []()
    {
        std::cout << "Welcome to Lambda expressions" << std::endl;
    };
    fn();
    std::cout << typeid(fn).name() << std::endl;
    auto sum = [](int x, int y)
    {
        return x + y;
    };
    std::cout << sum(5, 2) << std::endl;
    return 0;
}