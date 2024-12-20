#include "Savings.h"
Savings::Savings(const std::string &name, float balance, float rate) : Account(name, balance),
                                                                       m_Rate(rate)
{
    std::cout << "constructor of saving\n";
}
Savings::~Savings()
{
    std::cout << "Destructor of saving\n";
}

float Savings::GetInterestRate() const
{
    return m_Rate;
}

void Savings::AccumulateInterest()
{
    m_Balance += (m_Balance * m_Rate);
    std::cout << "bal" << m_Balance;
}