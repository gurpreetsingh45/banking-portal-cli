#ifndef SUPERMAN_ACCOUNT_H_
#define SUPERMAN_ACCOUNT_H_
#include <iostream>

namespace superman
{
    enum TransactionType
    {
        Deposit,
        Withdraw,
        FailedDeposit,
        FailedWithdraw
    };
    struct Transaction
    {
        double m_amount;
        TransactionType m_type;
        // Date date; will do this later on
    };
    class Account
    {
        char *m_name{};
        char *m_pin{};
        double m_balance{};
        Transaction **m_transactions{};
        unsigned int m_transactionCount{};

        void recordTransaction(TransactionType type, double amount);
        void getBalance();

    public:
        Account();
        Account(const char *name, const char *pin);
        ~Account();
        Account(const Account &other);
        Account &operator=(const Account &other);
        void depositMoney(double amount);
        void withdrawMoney(double amount);
        std::ostream &displayAccountBalance(std::ostream &ostr);
        std::ostream &displayAccountHistory(std::ostream &ostr);
    };
}

#endif // !SUPERMAN_ACCOUNT_H_