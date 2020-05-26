#include <iostream>
#include <string>
#include "bst.h"
#include <chrono>

binarySearchTree binarySearchTreeObj;
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

    binarySearchTreeObj.genDataS2();
    binarySearchTreeObj.remove(50);
   
    int x = binarySearchTreeObj.printHeight();
    std::cout << "Height is: " << x <<"\n\n";
    std::cout << "Binary Search Tree In Order is:" << "\n";
    binarySearchTreeObj.displayTreeInOrder();
    std::cout <<"\n";


    return 0;

}