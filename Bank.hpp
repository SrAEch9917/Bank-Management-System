#include <vector>
#include "Account.hpp"
#pragma once

class Bank {
    public:
        Bank(std::vector<Account>& bank);

        void createCSV();

        void loadCSV(const std::string& file);

        void updateCSV(const std::string& fileName);

        void bankUpdateCSV(const std::string& file);

        //Demo

        //void demo(Bank bank);

        //void selectSort(Bank bank);

        //void selectSearch(Bank bank);
        
        //Search
        int binarySearchByNumber(int accountNumber);

        int binarySearchByBalance(int accountNumber);

        int jumpSearchByNumber(int targetAccountNumber);

        int jumpSearchByBalance(int targetBalance);

        int linearSearchByBalance(int targetValue);

        int linearSearchByNumber(int targetValue);

        //Sort
        void insertionSortByBalance();

        void insertionSortByNumber();

        void swap_function(Account& A1, Account& A2);

        int partitionByNumber(int low, int high);

        int partitionByBalance(int low, int high);

        void merge(int left, int middle, int right, bool compare = true);

        void mergeSort(int left, int right, bool compare = true);

        void mergeSortByNumber(int left, int right);

        void mergeSortByBalance(int left, int right);

        void quickSortByBalance(int low, int high);

        void quickSortByNumber(int low, int high);


        //Operations

        void withdrawB(int& accountNumber, int amount);

        void depositB(int& accountNumber, int amount);

        void transferB(int& sender, int amount, int& receiver);

        int getBankSize();
        

    private:

    std::vector<Account> accountList;
};