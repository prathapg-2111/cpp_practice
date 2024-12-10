#include <iostream>
template <typename T>
struct Unnamed
{
    T operator()(T x, T y) const
    {
        return x + y;
    }
};

int main()
{
    auto fn = []()
    {
        std::cout << "Welcome to Lambda expressions" << std::endl;
    };
    fn();
    std::cout << typeid(fn).name() << std::endl;
    auto sum = [](auto x, auto y) noexcept(false)
    {
        return x + y;
    };
    std::cout << sum(5, 2) << std::endl;
    Unnamed<int> n;
    std::cout << n(5, 2) << std::endl;
    return 0;
}