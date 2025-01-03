#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Employee
{
    std::string m_Name;
    int m_Id;
    std::string m_ProgLang;

public:
    Employee(const std::string &n, int id, const std::string &pl) : m_Name(n),
                                                                    m_Id(id),
                                                                    m_ProgLang(pl)

    {
    }
    const std::string &GetName() const
    {
        return m_Name;
    }
    int GetId() const
    {
        return m_Id;
    }
    const std::string &GetProgrammingLanguage() const
    {
        return m_ProgLang;
    }
    // bool operator<(const Employee &e) const
    //{
    //  return m_Id < e.m_Id;
    //}
};

struct EmpIds
{
    std::vector<int> m_Ids;
    void operator()(const Employee &emp)
    {
        if (emp.GetProgrammingLanguage() == "C++")
        {
            m_Ids.push_back(emp.GetId());
        }
    }
};
void UserDefined()
{
    std::vector<Employee> v{
        Employee{"Prathap", 101, "C++"},
        Employee("Bob", 202, "Java"),
        Employee("Joey", 200, "C++")};
    std::sort(v.begin(), v.end(), [](const auto &e1, const auto &e2)
              { return e1.GetName() < e2.GetName(); });
    for (const auto &e : v)
    {
        std::cout << "Id:" << e.GetId()
                  << "| Name: " << e.GetName() << "| Language: " << e.GetProgrammingLanguage()
                  << std::endl;
    }

    int cppCount{};
    /*for (const auto &e : v)
    {
        if (e.GetProgrammingLanguage() == "C++")
            ++cppCount;
    }*/
    cppCount = std::count_if(v.begin(), v.end(), [](const auto &e)
                             { return e.GetProgrammingLanguage() == "C++"; });
    std::cout << "Count: " << cppCount << std::endl;
    auto itr = std::find_if(v.begin(), v.end(), [](const auto &e)
                            { return e.GetProgrammingLanguage() == "Java"; });
    if (itr != v.end())
        std::cout << "Found " << itr->GetName() << " is a Java programmer" << std::endl;
    std::for_each(v.begin(), v.end(), [](const auto &e)
                  { std::cout << e.GetName() << std::endl; });

    auto foundIds = std::for_each(v.begin(), v.end(), EmpIds());
    for (int id : foundIds.m_Ids)
    {
        std::cout << "Id" << id << std::endl;
    }
}

struct EmpCompare
{
    bool operator()(const Employee &e1, const Employee &e2) const
    {
        return e1.GetId() < e2.GetId();
    }
};
void Set()
{
    std::set<Employee, EmpCompare> v{
        Employee{"Prathap", 1010, "C++"},
        Employee("Bob", 202, "Java"),
        Employee("Joey", 200, "Go lang")};
    // std::sort(v.begin(), v.end(), [](const auto &e1, const auto &e2)
    //         { return e1.GetName() < e2.GetName(); });
    for (const auto &e : v)
    {
        std::cout << "Id:" << e.GetId()
                  << "| Name: " << e.GetName() << "| Language: " << e.GetProgrammingLanguage()
                  << std::endl;
    }
}

int main()
{
    UserDefined();
    // Set();
    return 0;
}