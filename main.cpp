#include <iostream>
#include <string>
#include "bst.h"
#include "bstdsw.h"
#include <chrono>

binarySearchTree binarySearchTreeObj;
bstdsw bstdswObj;

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


/*** Section 1********************
    binarySearchTreeObj.genDataS2();
    bool removal = binarySearchTreeObj.remove(50);
    std::cout <<"Removal is: " << removal <<"\n";
   
    int x = binarySearchTreeObj.printHeight();
    std::cout << "Height is: " << x <<"\n\n";
    std::cout << "Binary Search Tree In Order is:" << "\n";
    binarySearchTreeObj.displayTreeInOrder();
    std::cout <<"\n";
*************/

// Part 2
 bstdswObj.genDataS2();
    bool removal = bstdswObj.remove(50);
    std::cout <<"Removal is: " << removal <<"\n";
   
    int x = bstdswObj.printHeight();
    std::cout << "Height is: " << x <<"\n\n";
    std::cout << "Binary Search Tree In Order is:" << "\n";
    bstdswObj.displayTreeInOrder();
    std::cout <<"\n";

    return 0;

}