#include <vector>
#include "Account.hpp"
#include "Bank.hpp"
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <random>
#include <iostream>


Bank::Bank(std::vector<Account>& bank) : accountList(bank) {}

//CSV functions
void Bank::createCSV() {
        srand(time(0));

    int amount = 1000000;
    std::vector<int> numbers;

    std::vector<std::string> firstNames = {"James", "Mary", "Robert", "Patricia", "John", "Jennifer", "Michael", "Linda", 
      "David", "Elizabeth", "William", "Barbara", "Richard", "Susan", "Joseph", "Jessica", 
      "Thomas", "Sarah", "Christopher", "Karen", "Charles", "Lisa", "Daniel", "Nancy", 
      "Matthew", "Sandra", "Anthony", "Betty", "Mark", "Ashley", "Donald", "Emily", 
      "Steven", "Kimberly", "Andrew", "Margaret", "Paul", "Donna", "Joshua", "Michelle", 
      "Kenneth", "Carol", "Kevin", "Amanda", "Brian", "Melissa", "George", "Deborah", 
      "Timothy", "Stephanie"};  

    std::vector<std::string> lastNames = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", 
      "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", 
      "Thomas", "Taylor", "Moore", "Jackson", "Martin", "Lee", "Perez", "Thompson", "White", 
      "Harris", "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson", "Walker", "Young", 
      "Allen", "King", "Wright", "Scott", "Torres", "Nguyen", "Hill", "Flores", 
      "Green", "Adams", "Nelson", "Baker", "Hall", "Rivera", "Campbell", "Mitchell", 
      "Carter", "Roberts"}; 
    
    for (int i = 0; i < amount; i++){
      numbers.push_back(i);
    }  

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(numbers.begin(), numbers.end(), g);    

    std::ofstream file("accountData.csv");

    file << "Account,First,Last,Balance\n"; 
    for (int i = 0; i < amount; i++){
      file << numbers[i] << ","
           << firstNames[rand()% 50] << ","
           << lastNames[rand()% 50] << ","
           << rand()% 20001 << "\n";
    }

    file.close();

    std::cout << "1 million accounts have been created." << std::endl;
}

void Bank::loadCSV(const std::string& fileName){
  std::ifstream file(fileName);

  if(!file.is_open()){
    std::cout << "Error: File not found.";
    return;
  }

  accountList.reserve(1000000);

  std::string line;
  std::getline(file, line);

  while(std::getline(file, line)){
    std::stringstream s(line);
    std::string account, first, last, bal;

    std::getline(s, account, ',');
    std::getline(s, first, ',');
    std::getline(s, last, ',');
    std::getline(s, bal);

    accountList.emplace_back(std::stoi(account), first, last, std::stoi(bal));
  }
  file.close();
}

void Bank::updateCSV(const std::string& fileName){
  std::ofstream file(fileName);

  if(!file.is_open()){
    std::cout << "Error: File not found.";
    return;
  }

  file << "Account,First,Last,Balance\n";

  for(const auto & account : accountList){
    file << account.getAccountNumber() << ","
         << account.getFirstName() << ","
         << account.getLastName() << ","
         << account.getBalance() << "\n";
  }

  file.close();
}

//Demo functions
void Bank::demo(Bank bank) {
    int answer;

    std::cout << "Welcome to the Big City Bank. " 
              << "Today we'll be familiarizing you with our banking system. "
              << "Firstly, we'll be going through the various means of sorting all our bank accounts."
              << "Then, we'll move on to how to find a particular account. "
              << "Type 1 when you're ready to begin. " << std::endl;
    std::cin >> answer;

    selectSort(bank);
    selectSearch(bank);
    
}

void Bank::selectSort(Bank bank) {
    int answer;
    std::cout << "There are several means of organizing our existing accounts. "
              << "These would include insertion sort, merge sort and quick sort. "
              << "Each algorithm has a rate of completion, some are better than others. "
              << "Here are your options: " << std::endl;
    std::cout << "Insertion Sort by Number: 1     Merge Sort by Number: 2    Quick Sort by Number: 3" << std::endl;
    std::cout << "Insertion Sort by Balance: 4     Merge Sort by Balance: 5    Quick Sort by Balance: 6" << std::endl;
    std::cin >> answer;

    while(answer > 6 || answer < 0){
        std::cout << "Please make a choice within the selection. " << std::endl;
        std::cin >> answer;
    }

    switch (answer) {
        case 1: bank.insertionSortByNumber(); break;
        case 2: bank.mergeSortByNumber(); break;
        case 3: bank.quickSortByNumber(); break;
        case 4: bank.insertionSortByBalance(); break;
        case 5: bank.mergeSortByBalance(); break;
        case 6: bank.quickSortByBalance(); break;
    }

    std::cout << "Bank accounts have now been sorted according to your selection. " << std::endl;
}

void Bank::selectSearch(Bank bank) {
    int answer;
    std::cout << "Now you can select how you would like to search for an account. "
              << "Remain consistent in your selection. For instance, if you opted for a sort by number, continue to search by account number. "
              << "Here are your options: "
              << "Binary Search by Number: 1  Jump Search by Number: 2  Linear Search by Number: 3 "
              << "Binary Search by Balance: 4  Jump Search by Balance: 5  Linear Search by Balance: 6 " << std::endl;

    while(answer > 6 || answer < 0){
        std::cout << "Please make a choice within the selection. " << std::endl;
        std::cin >> answer;
    }

    std::cout << "Now you can type the account number you wish to search for. " << std::endl;
    std::cin >> answer;

    switch (answer) {
        case 1: bank.binarySearchByNumber(answer); break;
        case 2: bank.jumpSearchByNumber(answer); break;
        case 3: bank.linearSearchByNumber(answer); break;
        case 4: bank.binarySearchByBalance(answer); break;
        case 5: bank.jumpSearchByBalance(answer); break;
        case 6: bank.linearSearchByBalance(answer); break;
    }
}

//Search functions
int Bank::binarySearchByNumber(int targetValue){
  int left = 0; 
  int right = accountList.size() - 1;

  while (left <= right){
    int middleIndex = left + (right - left)/2;
    int x = accountList[middleIndex].getAccountNumber();

    if (x == targetValue){
      return middleIndex;
    } else if (x < targetValue){
      left = middleIndex + 1;
    } else {
      right = middleIndex - 1;
    }
  }
    return -1;
}

int Bank::binarySearchByBalance(int targetValue){
  int left = 0; 
  int right = accountList.size() - 1;

  while (left <= right){

    int middleIndex = left + (right - left)/2;

    int x = accountList[middleIndex].getBalance();

    if (x == targetValue){
      return middleIndex;
    }

    else if (x < targetValue){
      left = middleIndex + 1;
    }

    else {
      right = middleIndex - 1;
    }
  }
    return -1;
}

int Bank::jumpSearchByNumber(int targetAccountNumber) {
    if(accountList.size() == 0) return;
    int vectorSize =  accountList.size();
    int blockStartIndex = 0;
    int blockEndIndex = std::sqrt(vectorSize);



    while(accountList[std::min(blockEndIndex, vectorSize - 1)].getAccountNumber() < targetAccountNumber) {
        blockStartIndex = blockEndIndex;
        blockEndIndex += std::sqrt(vectorSize);

        if (blockStartIndex >= accountList.size()) return -1;
    }

    while(accountList[blockStartIndex].getAccountNumber() < targetAccountNumber) {
        blockStartIndex++;

        if(blockStartIndex == std::min(blockEndIndex, vectorSize)) {
            return -1;
        }
    }

    if(accountList[blockStartIndex].getAccountNumber() == targetAccountNumber) {
        return blockStartIndex;
    }

    return -1;
}

int Bank::jumpSearchByBalance(int targetBalance) {
    if(accountList.size() == 0) return;
    int vectorSize =  accountList.size();
    int blockStartIndex = 0;
    int blockEndIndex = std::sqrt(vectorSize);



    while(accountList[std::min(blockEndIndex, vectorSize - 1)].getAccountNumber() < targetBalance) {
        blockStartIndex = blockEndIndex;
        blockEndIndex += std::sqrt(vectorSize);

        if (blockStartIndex >= accountList.size()) return -1;
    }

    while(accountList[blockStartIndex].getBalance() < targetBalance) {
        blockStartIndex++;

        if(blockStartIndex == std::min(blockEndIndex, vectorSize)) {
            return -1;
        }
    }

    if(accountList[blockStartIndex].getBalance() == targetBalance) {
        return blockStartIndex;
    }

    return -1;
}

int Bank::linearSearchByNumber(int targetValue){
    for(int i = 0; i < accountList.size(); i++){
        if(accountList[i].getAccountNumber() == targetValue){
            return i;
        }
    }
    return -1;
}

int Bank::linearSearchByBalance(int targetValue){
    for(int i = 0; i < accountList.size(); i++){
        if(accountList[i].getBalance() == targetValue){
            return i;
        }
    }
    return -1;
}

//Sort functions
void Bank::insertionSortByNumber(){
  for (int i = 1; i < accountList.size(); i++){
    Account key = accountList[i]; 
    int j = i - 1;

    while (j >= 0 && accountList[j].getAccountNumber() > key.getAccountNumber()){
      accountList[j + 1] = accountList[j]; 
      j--; //
  }

    accountList[j + 1] = key;
  }
}

void Bank::insertionSortByBalance(){
  for (int i = 1; i < accountList.size(); i++){
    Account key = accountList[i];
    int j = i - 1; 
    
    while (j >= 0 && accountList[j].getBalance() > key.getBalance()){
      accountList[j + 1] = accountList[j]; 
      j--;
  }

    accountList[j + 1] = key;
  }
}

void Bank::swap_function(Account& A1, Account& A2){
  Account temporary = A1;
  A1 = A2;
  A2 = temporary;
}

int Bank::partitionByNumber(int low, int high){

  // the last element is gonna be the pivot element
  Account pivot = accountList[high];
  int i = low - 1; // the index of the smaller element

    for (int j = low; j < high; j++){
      // current account # smaller than pivot element
      if (accountList[j].getAccountNumber() < pivot.getAccountNumber()){
        i++; // increment i so that the smaller than pivot section is moved forward
        swap_function(accountList[i], accountList[j]);
      }
    }

    // Swap the pivot w/ higher
    swap_function(accountList[i + 1], accountList[high]);
    return i + 1;
  
  }

int Bank::partitionByBalance(int low, int high){
  Account pivot = accountList[high];
  int i = low - 1;

    for (int j = low; j < high; j++){
      if (accountList[j].getBalance() < pivot.getBalance()){
        i++;
        swap_function(accountList[i], accountList[j]);
      }
    }
  
    swap_function(accountList[i + 1], accountList[high]);
    return i + 1;
  
  }

void Bank::merge(int left, int middle, int right, bool compare = true){

    std::vector<Account> left_side;
    std::vector<Account> right_side;

    for (int i = left; i <= middle; i++){
      left_side.push_back(accountList[i]);
    }
    for (int i = middle + 1; i <= right; i++){
      right_side.push_back(accountList[i]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < left_side.size() && j < right_side.size()){
        if (compare){
            if (left_side[i].getAccountNumber() <= right_side[j].getAccountNumber()){
                accountList[k++] = left_side[i++];
            } else {
                accountList[k++] = right_side[j++];
            }
        } else {
            if (left_side[i].getBalance() <= right_side[j].getBalance()){
                accountList[k++] = left_side[i++];
            } else {
                accountList[k++] = right_side[j++];
            }
        }
    }

    // Put leftover elements from left side if right side had less elements
    while (i < left_side.size()){
      accountList[k++] = left_side[i++];
    }
    // Put leftover elements from right side if left side had less elements
    while (j < right_side.size()){
      accountList[k++] = right_side[j++];
    }
}

void Bank::mergeSort(int left, int right, bool compare = true){

    if (left >= right){
        return;
    }
  
    int middle = (left + right)/2; // find the middle index

    mergeSort(left, middle, compare);
    mergeSort(middle + 1, right, compare);

    merge(left, middle, right, compare);
}

void Bank::mergeSortByNumber(int left, int right) {
    mergeSort(0, accountList.size() - 1, true);
}

void Bank::mergeSortByBalance(int left, int right) {
    mergeSort(0, accountList.size() - 1, false);
}

void Bank::quickSortByNumber(int low, int high) {
    if (low < high){
    int pivot = partitionByNumber(low, high);

    quickSortByNumber(low, pivot - 1);
    quickSortByNumber(pivot + 1, high);
  }
}

void Bank::quickSortByBalance(int low, int high) {
    if (low < high){
        int pivot = partitionByBalance(low, high);

        quickSortByBalance(low, pivot - 1);
        quickSortByBalance(pivot + 1, high);
    }
}

//Bank Operations
void Bank::withdrawB(int& accountNumber, int amount) {
    accountList[binarySearchByNumber(accountNumber)].withdraw(amount);
}

void Bank::depositB(int& accountNumber, int amount) {
    accountList[binarySearchByNumber(accountNumber)].deposit(amount);
}

void Bank::transferB(int& sender, int amount, int& receiver) {
    accountList[binarySearchByNumber(sender)].withdraw(amount);
    accountList[binarySearchByNumber(receiver)].deposit(amount); 
}

int Bank::getBankSize() {
    return accountList.size();
}