#include <iostream>

class Integer
{
    int *m_pInt;

public:
    Integer();
    Integer(int value);
    // copy constructor
    Integer(const Integer &obj);
    // move constructor
    Integer(Integer &&obj);

    int GetValue() const;
    void SetValue(int value);
    ~Integer();
};