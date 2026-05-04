#include <string>
#include <iostream>
#pragma once

class Account {
    public:
        Account(int accountNumber, int balance, std::string first, std::string last);

        //int accountNumberGenerator() {
        //    std::string account = "0";
        //    std::string numChars = "0123456789";

        //    for(int i = 0; i < 6; i++) {
        //        int randomNum = rand() % 11;
        //        account[i] = numChars[randomNum];
        //    }

        //    return std::stoi(account);
        //}

        //int balanceGenerator() {
        //    int randomNum = rand() % 2000001;
        //    return randomNum;
        //}

        std::string getFirstName() const;

        std::string getLastName() const;

        int getBalance() const;

        int getAccountNumber() const;

        void withdraw(int amount);

        void deposit(int amount);

        void transfer(Account& sender, int amount, Account& receiver);

        bool detectError(int amount);

    private:

        int accountNumber;
        int balance;
        std::string first;
        std::string last;
};




//sets, vector
//chrono: time testing for sorting and searching