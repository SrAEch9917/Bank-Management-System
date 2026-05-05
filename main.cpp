#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <vector>
#include <ctime>
#include <cstdlib>

int main(){

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

    int answer;

    std::cout << "Hello, welcome your first day at Big City Bank. " 
              << "Today we'll be familiarizing you with our banking system. "
              << "Firstly, we'll be going through the various means of sorting all our bank accounts."
              << "Then, we'll move on to how to find a particular account when assisting a customer. "
              << "Type 1 when you're ready to begin. " << std::endl;

    std::cin >> answer;

    std::cout << "There are several means of organizing our existing accounts. "
              << "These ways would include insertion sort, merge sort and quick sort. "
              << "Each algorithm has a rate of completion, some better than others. ";


    

    
}