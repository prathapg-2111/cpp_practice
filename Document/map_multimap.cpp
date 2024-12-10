#include <iostream>
#include <map>
void Map()
{
    std::map<int, std::string> m{
        {1, "Superman"},
        {2, "Batman"},
        {3, "Green lantern"}};
    m.insert(std::pair<int, std::string>(8, "Aquaman"));
    m.insert(std::make_pair(6, "Wonder woman"));

    m[0] = "Flash";
    auto itr = m.begin();
    // std::cout << itr->first << ":" << itr->second << std::endl;
    for (const auto &x : m)
    {
        std::cout << x.first << ":" << x.second << std::endl;
    }
}

int main()
{
    Map();
    return 0;
}