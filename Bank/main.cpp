#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"

int main()
{
    // Account *acc = new Savings("Bob", 1000, 0.5f);
    Savings acc("Bob", 1000, 50);
    try
    {
        Transact(acc);
    }
    catch (std::exception &ex)
    {
        std::cout << "Exception" << ex.what() << '\n';
    }
    std::cout << "sizeof account" << sizeof(acc) << std::endl;
    // std::cout << "Initial Balance:" << acc.GetBalance() << std::endl;
    //  acc.Deposit(200);
    //  acc.Withdraw(980);
    // delete acc;
    // std::cout << "Balance:" << acc.GetBalance() << std::endl;
    return 0;
}