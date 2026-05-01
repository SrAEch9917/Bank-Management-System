#include "Account.hpp"

Account::Account(int accountNumber, int balance, std::string first, std::string last) {}

int Account::accountNumberGenerator() {
    std::string account;
    std::string numChars = "0123456789";
    for(int i = 0; i < 6; i++) {
        int randomNum = rand() % 11;
        account[i] = numChars[randomNum];
    }
    
    //add functionality for checking duplicates

    return std::stoi(account);
}

int Account::balanceGenerator() {
    int randomNum = rand() % 2000001;
    return randomNum;
}

int Account::getBalance() const {
    return balance;
}

void Account::withdraw(int amount) {
    if(detectError(amount)) return;

    balance -= amount;
}

void Account::deposit(int amount) {
    balance += amount;
}

void Account::transfer(Account& sender, int amount, Account& receiver) {
    sender.withdraw(amount);
    receiver.deposit(amount);
}

bool Account::detectError(int amount) {
    if(getBalance() < amount) {
        std::cout << "Inadequate funds for transaction. " << std::endl;
        return true;
    }

    return false;
} 
