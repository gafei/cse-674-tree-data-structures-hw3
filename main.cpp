#include <iostream>
#include <string>
#include "bst.h"
#include "bstdsw.h"
#include "bstavl.h"
#include <chrono>

binarySearchTree binarySearchTreeObj;
binarySearchTree binarySearchTreeObj2;
bstdsw bstdswObj;
bstdsw bstdswObj2;
bstavl bstavlObj;
bstavl bstavlObj2;

int main(int argc, char *argv[]){

    /******
    binarySearchTreeObj.insert(8);
    binarySearchTreeObj.insert(12);    
    binarySearchTreeObj.insert(5);
    binarySearchTreeObj.insert(4);

    binarySearchTreeObj.insert(2);
    binarySearchTreeObj.insert(15);
    //binarySearchTreeObj.insert(5);
    //binarySearchTreeObj.insert(7);
    *****/
    //binarySearchTreeObj.genDataS1();

// Part 1 BST 
/**********************
    std::cout << "Start of S1 Data, numbers are in order from 1-100 into Binary Search Tree: \n";
    binarySearchTreeObj.genDataS1();
    bool removals1 = binarySearchTreeObj.remove(50);
    std::cout <<"Removal is: " << removals1 <<"\n";
    int s1 = binarySearchTreeObj.printHeight();
    std::cout << "After removal of 50, Height is: " << s1 <<"\n\n";
    std::cout << "After removal of 50, Binary Search Tree In Order is:" << "\n";
    binarySearchTreeObj.displayTreeInOrder();
    std::cout <<"\n\n";

    std::cout << "Start of S2 Data, random data from 1-100 into the Binarch Search Tree: \n";
    binarySearchTreeObj2.genDataS2();
    bool removals2 = binarySearchTreeObj2.remove(50);
    std::cout <<"Removal is: " << removals2 <<"\n";
    int s2 = binarySearchTreeObj2.printHeight();
    std::cout << "After removal of 50, Height is: " << s2 <<"\n\n";
    std::cout << "After removal of 50, Binary Search Tree In Order is:" << "\n";
    binarySearchTreeObj2.displayTreeInOrder();
    std::cout <<"\n\n";
*********************/
// Part 2 DSW Algorithm
   
   // genDataS1, generates numbers in order 1-100.
/***************    
    std::cout << "Start of S1 Data, numbers are in order from 1-100 into BST: \n";
    bstdswObj.genDataS1();
    bool removal1 = bstdswObj.remove(50);
    std::cout <<"Removal of 50 is: " << removal1 <<"\n";
    
    int x1 = bstdswObj.printHeight();
    std::cout << "After removal of 50, Height is: " << x1 <<"\n\n";
    std::cout << "After removal of 50, Binary Search Tree In Order is:" << "\n";
    bstdswObj.displayTreeInOrder();
    std::cout <<"\n\n\n";

   
    std::cout << "Start of S2 Data, random data from 1-100 into the BST: \n";
    bstdswObj2.genDataS2(); 
    bool removal2 = bstdswObj.remove(50);
    std::cout <<"Removal is: " << removal2 <<"\n";

   
    int x2 = bstdswObj2.printHeight();
    std::cout << "After removal of 50, Height is: " << x2 <<"\n\n";
    std::cout << "After removal of 50, Binary Search Tree In Order is:" << "\n";
    bstdswObj2.displayTreeInOrder();
    std::cout <<"\n";
************************/
    return 0;

}