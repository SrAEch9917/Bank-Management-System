#include <iostream>
#include <chrono>
#include "Bank.hpp"
#include "Account.hpp"

using namespace std::chrono;

int main(){
    std::vector<Account> accounts;

    Bank testBank(accounts);
    testBank.loadCSV("accountData.csv");
    int choice;
    
    do {
        std::cout << "Choose an option\n1 - Search\n2 - Sort\n3 - Exit" << std::endl;
        std::cin >> choice;

        switch(choice){

            // Searching algorithms
            case 1:
            {

                // Linear Search

                auto begin = high_resolution_clock::now();
                int result = testBank.linearSearchByNumber(180393);
                auto finish = high_resolution_clock::now();

                std::cout << "Searching for account number 180393..." << std::endl;
                std::cout << "Linear Search: O(n)" << std::endl;
                std::cout << "Found at index: " << result << std::endl;
                std::cout << "Time: " << duration_cast<microseconds>(finish-begin).count()
                          << " microseconds" << std::endl;

                // Jump and Binary Search require already sorted vector
                // Use Quick Sort to sort the vector prior to Jump/Binary Search

                // Jump Search
                testBank.quickSortByNumber();

                auto begin1 = high_resolution_clock::now();
                int result1 = testBank.jumpSearchByNumber(180393);
                auto finish1 = high_resolution_clock::now();

                std::cout << "Jump Search: O(√n)" << std::endl;
                std::cout << "Found at index: " << result1 << std::endl;
                std::cout << "Time: " << duration_cast<microseconds>(finish1-begin1).count()
                          << " microseconds" << std::endl;

                // Binary Search
                auto begin2 = high_resolution_clock::now();
                int result2 = testBank.binarySearchByNumber(180393);
                auto finish2 = high_resolution_clock::now();

                std::cout << "Binary Search: O(logn)" << std::endl;
                std::cout << "Found at index: " << result2 << std::endl;
                std::cout << "Time: " << duration_cast<microseconds>(finish2-begin2).count()
                          << " microseconds" << std::endl;

            break;

            }

            // Sorting algorithms
            case 2:
            {
                /*
                testBank.loadCSV("accountData.csv");
                // Insertion sort
                auto begin3 = high_resolution_clock::now();
                testBank.insertionSortByNumber();
                auto finish3 = high_resolution_clock::now();

                std::cout << "Insertion Sort:" << std::endl;
                std::cout << "Time: " << duration_cast<microseconds>(finish3-begin3).count()
                          << " microseconds" << std::endl;
                */

                testBank.loadCSV("accountData.csv");
                // Quick sort
                auto begin4 = high_resolution_clock::now();
                testBank.quickSortByNumber();
                auto finish4 = high_resolution_clock::now();

                std::cout << "Quick Sort:" << std::endl;
                std::cout << "Time: " << duration_cast<microseconds>(finish4-begin4).count()
                          << " microseconds" << std::endl;

                testBank.loadCSV("accountData.csv");
                // Merge sort
                auto begin5 = high_resolution_clock::now();
                testBank.mergeSortByNumber();
                auto finish5 = high_resolution_clock::now();

                std::cout << "Merge Sort: " << std::endl;
                std::cout << "Time: " << duration_cast<microseconds>(finish5-begin5).count()
                          << " microseconds" << std::endl;

                break;
            }

            case 3:
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice... Try again." << std::endl;

        }
    } while (choice != 3);

}