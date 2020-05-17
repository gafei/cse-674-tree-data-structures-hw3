#include <iostream>
#include <string>
#include "bst.h"
#include <chrono>

binarySearchTree binarySearchTreeObj;
int main(int argc, char *argv[]){


    binarySearchTreeObj.insert(5);
    binarySearchTreeObj.insert(7);
    binarySearchTreeObj.displayTree();


    return 0;

}