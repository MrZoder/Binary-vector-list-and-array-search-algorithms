// ADS A3 TASK 1_Zain_Zahab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <chrono> //High res clock
#include <stdlib.h> /* srand, rand */
#include <time.h> // time 
#include <random>
#include <iterator>

#include <vector> //std::vector to store ints 
#include <list> 
#include <array>// std::list
#include <set>
#include <algorithm>
#include <iterator>

#include "BST.h"
#include "Node.h"
#include "main.h"//Binary search tree 
#include "Colored Menu.h" //Extra stuff


/*Task 1
The new task instead will use BST, Array, Vector, List instead of BST, List, BBST.

The requirements are now:

Step 1:
Implement a BST with integer based nodes.

Step 2:
IGNORE

Step 3:
Insert 150K random numbers into std::list, std::vector, array (use malloc), and BST. Make sure the same numbers are inserted into each.

Step 4:
Present the user with a simple menu:
Select an option:
1) Search for a number all data structures
2) Exit
Enter in option (1–2):
If the user selects 1, the user is asked to input a number. This number is searched for in all data structures recording
how long it takes in milliseconds to do each. If the number is found in the structures, display the time taken to find it in each structure. If
not, let the user know that the number could not be found in any of them and still show the time to complete the search on each structure.
tldr; follow existing steps but replace BBST (that you'd need to implement yourself) with std::vector and array.*/
int choice;

std::set<int> checkNum;//avoid duplicating nums 
using std::chrono::duration_cast; //define timer 
using std::chrono::milliseconds;
typedef std::chrono::high_resolution_clock Clock;
/*void searchArray(int* p, int element) {
    for (int i = 0; i < 150000; i++) {
        if (p[i] == element) {
            std::cout << element << ": found in the array at index " << i << std::endl;
            break;
        }
        if (i == 150000) {
            std::cout << "Element Not Present in Input Array" << std::endl;
        }
    }
}*/
int main(void)
{
   
    
    ColoredMenu();
    std::cin >> choice;

    do
    {
        if (choice == 1)
        {
            std::cout << "\nBeging Number Generation... ";
            srand(time(NULL));
            std::set<int> checkNum; //avoid duplicating nums 
            std::random_device rand; //  uniformly-distributed integer random number generator
            std::mt19937 gen(rand()); // mersenne twister 
            std::uniform_int_distribution<> distrib(1, 150000);
            Node* root = NULL;
            BinarySearchTree bst;

            while (checkNum.size() < 150000) {
                int random_number = ((distrib(gen) % 150000));
                checkNum.insert(random_number);
                root = bst.InsertNode(root, random_number); // Insert int BST
                
            }
           
            int* a = (int*)malloc(150000 * sizeof(int)); // Array
            
           
            std::list<int> list; // List
            for (auto element : checkNum) {
                list.push_back(element);
            }

            std::vector<int> vec; // Vector
            for (auto element : checkNum) {
                vec.push_back(element);
            }
            //Generate Numbers
            std::cout << "Amount of Numbers Generated: " << checkNum.size() << std::endl;
            int userNum;
            std::cout << "\n\t\t\t\t|--- READY TO SEARCH ---|\n \n\Pleae enter the number you would like to find: ";
            std::cin >> userNum;
            std::cout << "Beep Boop...";
            Sleep(500);
            std::cout << "\nBeep Boop...";
            Sleep(500);
            std::cout << "\nBeep Boop...";
            Sleep(500);
            std::cout << "\nBeep Boop...";
            Sleep(500);
            system("Color 0A");
            CompletedMenu();
            std::cin >> choice;
            Sleep(300);
            LoadingMenu();
            std::cout << "\n\t\t\t\t\t --------------------------" << std::endl;
            Sleep(500);
            LoadBGColor();
            std::cout << "Data Structure Times:";
            //Begin vector Timer
            auto start = Clock::now();
            if (std::find(vec.begin(), vec.end(), userNum) != vec.end()) {
                std::cout << "\n-------------------" << std::endl;
                std::cout << "\nVector Located: " << userNum << std::endl;
            }
            else {
                std::cout << "\nError Vector Cannot Locate: " << userNum  << std::endl;
            }
            auto end = Clock::now();
            auto vecMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            std::cout << "\t --> " << vecMs << " Milliseconds to complete search..." << std::endl;
        
           //Begin List timer:
            auto listStart = Clock::now();
            if(std::find(list.begin(), list.end(),userNum) != list.end())
            {
                std::cout << "\n-------------------" << std::endl;
                std::cout << "\nList Located: " << userNum  << std::endl;
                
            }else{
                std::cout << "\nError List cannot Locate: " << userNum << std::endl;
            }
            auto listEnd = Clock::now();
            auto listMs = std::chrono::duration_cast<std::chrono::milliseconds>(listEnd - listStart).count();
            std::cout << "\t --> " << listMs << " Millisecond to complete search..." << std::endl;
          
            //Begin array timer 
            auto arrayStart = Clock::now();
   
            auto arrayNum = checkNum.cbegin();
            auto ci = checkNum.begin();
            for (int i = 0; i < checkNum.size(); ++i)
            {
                //a[i] = arrayNum
                //i wanna cry

               if(a[i] == userNum)
               {
                   std::cout << "\n-------------------" << std::endl;
                   std::cout << "\Array Located: " << userNum << std::endl;
                   break;
               }
               else {
                   std::cout << "\nError Array cannot Locate: " << userNum << std::endl;
                   break;
               }
               //what am i doing wrong please tell me.
              
                
            }
            
            
           
            auto arrayEnd = Clock::now();
            auto arrayMs = std::chrono::duration_cast<std::chrono::milliseconds>(arrayEnd - arrayStart).count();
            std::cout << "\t --> " << arrayMs << " Milliseconds to complete search..." << std::endl;
            
            //Begin Bst Timer
            auto bstStart = Clock::now();
            if (NodeExists(root, userNum)) {
                std::cout << "\n-------------------" << std::endl;
                std::cout << "\nBinary Search Tree Located: " << userNum  << std::endl;
            }
            else {
                std::cout << "\n Error Binary Search Tree Cannot locate: " << userNum << std::endl;
            }
            auto bstEnd = Clock::now();
            auto bstMs =
                std::chrono::duration_cast<std::chrono::milliseconds>(bstEnd - bstStart).count();
            std::cout << "\t --> " << bstMs << " Milliseconds to complete search..." << std::endl;
        }
        system("pause");
    
    } while (choice != 2);
    
    
 /*   BinarySearchTree* root = new BinarySearchTree(100);
    root->AddNode(new BinarySearchTree(77));  //Nodes 
    root->AddNode(new BinarySearchTree(67));*/

   
    //std::vector<int> elements; // vector to store 150k nums 
   // std::list<int> list;       // list to store 150k nums
    //int* a = (int*)malloc(150000 * sizeof(int)); //array to store 150k nums
   
   
   

  

   /*while (checkNum.size() < 150000)
    {
        int randomNumber = gen32();
        checkNum.insert(randomNumber);
    }
    std::cout << "Amount of random numbers are: " << checkNum.size() << std::endl;*/ 
    
   /*
   auto start = Clock::now();
   for (auto element : checkNum)
    {
        elements.push_back(element);
    }*/ 


   /* for (int i = 0; i < 150000; ++i)
    {
        
        elements.push_back(randomNumber);
        list.push_back(randomNumber);
        a[i] = randomNumber;
    
    }
    
    
    //printing specific elements
   
    std::cout << elements[80]<< std::endl;
    std::cout << a[80] << std::endl;
    auto list_index = list.begin();
    std::advance(list_index, 1230);
    std::cout << *list_index << std::endl;
    */

   /*auto end = Clock::now();
    milliseconds ms = duration_cast<milliseconds>(end - start);
    std::cout << "milliseconds " << ms.count() << std::endl;
    */ 
    system("pause");
    //return 0;
}

/*void VectorSearch(std::vector<int> elements)
{
    
    auto start = Clock::now();
    for (auto element : checkNum)
    {
        elements.push_back(element);
    }
    auto end = Clock::now();
    milliseconds ms = duration_cast<milliseconds>(end - start);
    std::cout << "It took Vector " << ms.count() << " milliseconds Long " << std::endl;
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
