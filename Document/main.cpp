#include <iostream>
#include "Integer.h"

class Employee
{
    std::string m_Name;
    Integer m_Id;

public:
    Employee(const std::string &name, const Integer &id) : m_Name{name},
                                                           m_Id{id}
    {
    }
    Employee(const std::string &&name, const Integer &&id) : m_Name{name},
                                                             m_Id{std::move(id)}
    {
        std::cout << "std::string &&name, Integer &&id" << std::endl;
    }
};

int main()
{
    Employee emp("Prathap", 100);
    return 0;
}