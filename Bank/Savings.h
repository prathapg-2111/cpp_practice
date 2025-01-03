#pragma once
#include <iostream>
#include "Account.h"
class Savings : public Account
{
    float m_Rate;

public:
    Savings(const std::string &name, float balance, float rate);
    ~Savings();
    float GetInterestRate() const;
    void AccumulateInterest();
};