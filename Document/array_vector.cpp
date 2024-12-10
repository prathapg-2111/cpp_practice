#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <list>
#include <forward_list>
void Array()
{
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] = i;
    }
    auto itr = arr.begin();
    for (auto x : arr)
    {
        std::cout << x << "";
    }
    std::cout << std::endl;
}

void Vector()
{
    std::vector<int> coll{1, 2, 3, 4};
    for (int i = 0; i < 5; ++i)
    {
        coll.push_back(i * 10);
        // std::cout << coll.size() << std::endl;
    }
    coll[0] = 100;
    auto itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << std::endl;
    }
    coll.insert(coll.begin(), 700);
    coll.erase(coll.end() - 5);
    coll.pop_back();
}

void Deque()
{
    std::deque<int> coll;
    for (int i = 0; i < 5; ++i)
    {
        coll.push_back(i * 10);
    }
    for (int i = 0; i < 5; ++i)
    {
        coll.push_front(i * 10);
    }
    coll[0] = 100;
    auto itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << std::endl;
    }
    coll.insert(coll.begin(), 700);
    coll.erase(coll.end() - 5);
    coll.pop_back();
    coll.pop_front();
}

void List()
{
    std::list<int> coll;
    for (int i = 0; i < 5; i++)
    {
        coll.push_back(i * 10);
    }

    auto itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << " ";
    }
    std::cout << std::endl;
    itr = coll.begin();
    coll.insert(itr, 800);
    coll.insert(itr, 80);
    // coll.erase(itr);
    while (itr != coll.end())
    {
        std::cout << *itr++ << " ";
    }
}
void ForwardList()
{
    std::forward_list<int> coll;
}
int main()
{
    List();
    return 0;
}