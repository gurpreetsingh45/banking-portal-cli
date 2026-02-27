#include <cstring>
#include "../include/Account.h"

using namespace std;

namespace superman
{
    Account::Account()
    {
    }
    Account::~Account()
    {
        delete[] m_name;
        delete[] m_pin;
        for (int i{}; i < m_transactionCount; i++)
        {
            if (m_transactions[i])
                delete m_transactions[i];
        }
    }
    Account::Account(const char *name, const char *pin)
    {
        if (name)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
        if (pin)
        {
            m_pin = new char[strlen(pin) + 1];
            strcpy(m_pin, pin);
        }
    }
    Account::Account(const Account &other)
    {
        if (other.m_name)
        {
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
        }
        if (other.m_pin)
        {
            m_pin = new char[strlen(other.m_pin) + 1];
            strcpy(m_pin, other.m_pin);
        }
        for (int i{}; i < other.m_transactionCount; i++)
        {
            if (other.m_transactions[i])
            {
                // m_transactions[i] = new char[strlen(other.m_transactions[i]) + 1];
                // strcpy(m_transactions[i], other.m_transactions[i]);
                m_transactions[i] = new Transaction[other.m_transactionCount];
                *m_transactions[i] = *other.m_transactions[i];
            }
        }
        m_balance = other.m_balance;
        m_transactionCount = other.m_transactionCount;
    }
    Account &Account::operator=(const Account &other)
    {
        if (this != &other)
        {
            // clearing all the transactions first
            for (int i{}; i < m_transactionCount; i++)
            {
                delete m_transactions[i];
                m_transactions[i] = nullptr;
            }
            m_transactionCount = 0;

            if (other.m_name)
            {
                delete[] m_name;
                m_name = new char[strlen(other.m_name) + 1];
                strcpy(m_name, other.m_name);
            }
            if (other.m_pin)
            {
                delete[] m_pin;
                m_pin = new char[strlen(other.m_pin) + 1];
                strcpy(m_pin, other.m_pin);
            }
            for (int i{}; i < other.m_transactionCount; i++)
            {
                if (other.m_transactions[i])
                {
                    // delete[] m_transactions[i];
                    // m_transactions[i] = new char[strlen(other.m_transactions[i]) + 1];
                    // strcpy(m_transactions[i], other.m_transactions[i]);
                    delete m_transactions[i];
                    m_transactions[i] = new Transaction[other.m_transactionCount];
                    *m_transactions[i] = *other.m_transactions[i];
                }
            }
            m_balance = other.m_balance;
            m_transactionCount = other.m_transactionCount;
        }
        return *this;
    }
    void Account::depositMoney(double amount)
    {
        if (amount <= 0)
        {
            cerr << "Invalid depsoit Amount" << endl;
            recordTransaction(TransactionType::FailedDeposit, amount);
        }
        else
        {
            m_balance += amount;
            // recordTransaction will handle increasing transaction count
            recordTransaction(TransactionType::Deposit, amount);
        }
    }
    void Account::withdrawMoney(double amount)
    {
        if (amount > m_balance)
        {
            cerr << "Not Enough Balance" << endl;
            recordTransaction(TransactionType::FailedWithdraw, amount);
        }
        else
        {
            m_balance -= amount;
            recordTransaction(TransactionType::Withdraw, amount);
        }
    }
    ostream &Account::displayAccountBalance(ostream &ostr)
    {
        ostr << "Account balance: " << m_balance;
        return ostr;
    }
    ostream &Account::displayAccountHistory(ostream &ostr)
    {
        ostr << "Account Transaction History: \n";
        for (int i{}; i < m_transactionCount; i++)
        {
            if (i == m_transactionCount - 1)
            {
                ostr << m_transactions[i];
            }
            else
            {
                ostr << m_transactions[i] << "\n";
            }
        }
        return ostr;
    }
    // void recordTransaction(TransactionType type, double amount){
    //     switch (type)
    //     {
    //     case TransactionType::Deposit:

    //         break;

    //     default:
    //         break;
    //     }
    // }
}
