#pragma once
#include <string>
class Account
{
    std::string m_Name;
    int m_AccNo;
    static int m_ANGenerator;

protected:
    float m_Balance;

public:
    Account(const std::string &name, float balance);
    virtual ~Account();
    const std::string GetName() const;
    float GetBalance() const;
    int GetAccountNo() const;

    virtual void AccumulateInterest();
    virtual void Withdraw(float amount);
    virtual void Deposit(float amount);
    float GetInterestRate() const;
};