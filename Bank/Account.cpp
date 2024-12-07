#include "Account.h"
#include <iostream>
int Account::m_ANGenerator = 1000;
Account::Account(const std::string &name, float balance) : m_Name(name),
                                                           m_Balance(balance)
{
    std::cout << "constructor of account\n";
    m_AccNo = ++m_ANGenerator;
}
Account::~Account()
{
    std::cout << "destructor of account\n";
}

const std::string Account::GetName() const
{
    return std::string();
}

float Account::GetBalance() const
{
    return m_Balance;
}

int Account::GetAccountNo() const
{
    return m_AccNo;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(float amount)
{
    if (amount < m_Balance)
    {
        m_Balance -= amount;
    }
    else
    {
        std::cout << "InSufficient balance";
    }
}

void Account::Deposit(float amount)
{
    m_Balance += amount;
}

float Account::GetInterestRate() const
{
    return 0.0f;
}