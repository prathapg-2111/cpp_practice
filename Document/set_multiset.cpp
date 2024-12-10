#include <iostream>
#include <set>
#include <functional>
void Set()
{
    // std::set<int, std::greater<int>> s{8, 2, 3, 6, 9, 0};
    std::multiset<int, std::greater<int>> s{8, 2, 3, 6, 9, 0};

    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    auto itr = s.begin();
    while (itr != s.end())
    {
        std::cout << *itr++ << " ";
    }
    s.erase(0);
    s.erase(s.begin());
    itr = s.find(9);
    if (itr != s.end())
    {
        std::cout << "Element found" << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    auto found = s.equal_range(3);
    while (found.first != found.second)
    {
        std::cout << *found.first++ << " ";
    }
}

int main()
{
    Set();
    return 0;
}