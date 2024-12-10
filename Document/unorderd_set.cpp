#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

void UnSet()
{
    std::unordered_set<std::string> coll;
    coll.insert("Hulk");
    coll.insert("Batman");
    coll.insert("Green lantern");
    coll.insert("The flash");
    coll.insert("Wonder women");
    coll.insert("Iron man");
    coll.insert("Iron man");
    coll.insert("Iron man");
    coll.insert("Wolverine");
    for (const auto x : coll)
    {
        // std::cout << x << std::endl;
        std::cout << "Bucket count:" << coll.bucket(x) << "  contains:" << x << std::endl;
    }
    std::cout << "Bucket count:" << coll.bucket_count() << std::endl;
    std::cout << "number of elements:" << coll.size() << std::endl;
    std::cout << "load factor" << coll.load_factor() << std::endl;
}

void UnMap()
{
    std::unordered_map<std::string, std::string> coll;
    coll["Batman"] = "Brue Hayne";
    coll["Superman"] = "Clark kent";
    coll["Hulk"] = "Bruce Banner";

    for (const auto &x : coll)
    {
        std::cout << "Bucket # " << coll.bucket(x.first) << x.first << " " << x.second << std::endl;
    }
}
class Employee
{
    std::string m_Name;
    int m_Id;

public:
    Employee(const std::string &name, int id) : m_Name(name), m_Id(id) {}
    const std::string &GetName() const
    {
        return m_Name;
    }
    int GetId() const
    {
        return m_Id;
    }
};
struct EmployeeHash
{
    size_t operator()(const Employee &emp) const
    {
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.GetId());
        return s1 ^ s2;
    }
};

struct EmpEquality
{
    bool operator()(const Employee &e1, const Employee e2) const
    {
        return e1.GetId() == e2.GetId();
    }
};
void Hashes()
{
    std::hash<std::string> h;
    std::cout << "Hash:" << h("Hello") << std::endl;
    std::unordered_set<Employee, EmployeeHash, EmpEquality> coll;
    coll.insert(Employee("Umar", 123));
    coll.insert(Employee("Bob", 133));
    coll.insert(Employee("Joey", 423));

    for (const auto &x : coll)
    {
        std::cout << x.GetId() << ":" << x.GetName() << std::endl;
    }
}
int main()
{
    Hashes();
    return 0;
}