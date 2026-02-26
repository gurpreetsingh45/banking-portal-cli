#ifndef SUPERMAN_ACCOUNT_H_
#define SUPERMAN_ACCOUNT_H_
#include <iostream>

namespace superman{
    class Account{
        char *m_name{};
        char *m_pin{};
        double m_balance{};
        char *m_transactions[100]{};
        unsigned int m_transactionCount{};

    public:
        Account();
        Account(const char* name, const char* pin);
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