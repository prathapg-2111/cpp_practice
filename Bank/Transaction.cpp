#include <iostream>
#include "Transaction.h"
#include "Checking.h"
void Transact(Account *pAccount)
{
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance:" << pAccount->GetBalance() << std::endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();
    pAccount->Withdraw(170);
    // if (typeid(*pAccount) == typeid(Checking))
    //{
    //   Checking *pChecking = static_cast<Checking *>(pAccount);
    //  pChecking->GetMinimumBalance();
    // std::cout << "Minimum balance of checking" << pChecking->GetMinimumBalance() << std::endl;
    //}
    // Checking *pChecking = static_cast<Checking *>(pAccount);
    // pChecking->GetMinimumBalance();

    Checking *pChecking = dynamic_cast<Checking *>(pAccount);
    if (pChecking != nullptr)
    {
        std::cout << "Minimum balance of checking" << pChecking->GetMinimumBalance() << std::endl;
    }

    std::cout << "Interest rate:" << pAccount->GetInterestRate() << std::endl;
    std::cout << "Final balance:" << pAccount->GetBalance() << std::endl;
}

void Transact(Account &pAccount)
{
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance:" << pAccount.GetBalance() << std::endl;
    pAccount.Deposit(100);
    pAccount.AccumulateInterest();
    pAccount.Withdraw(170);
    // if (typeid(*pAccount) == typeid(Checking))
    //{
    //   Checking *pChecking = static_cast<Checking *>(pAccount);
    //  pChecking->GetMinimumBalance();
    // std::cout << "Minimum balance of checking" << pChecking->GetMinimumBalance() << std::endl;
    //}
    // Checking *pChecking = static_cast<Checking *>(pAccount);
    // pChecking->GetMinimumBalance();

    Checking &pChecking = dynamic_cast<Checking &>(pAccount);
    std::cout << "Minimum balance of checking" << pChecking.GetMinimumBalance() << std::endl;

    std::cout << "Interest rate:" << pAccount.GetInterestRate() << std::endl;
    std::cout << "Final balance:" << pAccount.GetBalance() << std::endl;
}