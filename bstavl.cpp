#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "bstavl.h"


bstavlNode* newNode(int key){

    bstavlNode *newNode = new bstavlNode();
    newNode->key = key;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->height = 1;

    return(newNode); 

}

bstavlNode* bstavl::rotateRight(bstavlNode *rootNode){

    bstavlNode *rootNodeLeft =rootNode->leftChild;
    bstavlNode *rootNodeLeftRightChild = rootNodeLeft->rightChild;

    rootNodeLeft->rightChild = rootNode; //
    rootNode->leftChild = rootNodeLeftRightChild; 

    //change heights here
    rootNode->height = getMax(printHeight(rootNode->leftChild), printHeight(rootNode->rightChild))+1;
    rootNodeLeft->height = getMax(printHeight(rootNodeLeft->leftChild), printHeight(rootNodeLeft->rightChild))+1;

    return rootNodeLeft;

}

bstavlNode* bstavl::rotateLeft(bstavlNode *rootNode){

    bstavlNode *rootNodeAbove =rootNode->rightChild;
    bstavlNode *rootNodeAboveRightChild = rootNodeAbove->leftChild;

    rootNodeAbove->leftChild = rootNode; //
    rootNode->rightChild = rootNodeAboveRightChild; 

    //change heights here
    rootNode->height = getMax(printHeight(rootNode->leftChild), printHeight(rootNode->rightChild))+1;
    rootNodeAbove->height = getMax(printHeight(rootNodeAbove->leftChild), printHeight(rootNodeAbove->rightChild))+1;

    return rootNodeAbove;

}


int bstavl::printHeight(bstavlNode *inputNode){

    if(inputNode==NULL){

        return 0;
    }
    else{
        return inputNode->height;
    }

} 
int bstavl::getMax(int a, int b){

    return ((a > b)) ? a : b;

}

int bstavl::getBalance(bstavlNode *inputNode){

    if(inputNode ==NULL){

        return 0;
    }
    return printHeight(inputNode->leftChild) - printHeight(inputNode->rightChild);

}

bstavlNode* bstavl::insert(bstavlNode *node, int key){


}