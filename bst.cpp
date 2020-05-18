#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "bst.h"

binarySearchTree::binarySearchTree(){

    root=NULL;


}
binarySearchTree::~binarySearchTree(){

    //destrutor
}

void binarySearchTree::insert(int key){

		bstNode *newNode = new bstNode(); // init a new node
		newNode->key = key;
		
		if (root == NULL) 
		{
			root = newNode; // if nothing is in the tree, create a newnode
			//newNode->key = key;
		}
		else {
			
			//insert a node into the tree
			
			bstNode *current = root; // changes as we go down the binary search tree
			bstNode *parent; // this repsrreesnets the parent of the current node
			
			while(true) {
				
				parent = current;
				if(key < current->key) {
					current = current->leftChild;
					
					if(current == NULL) { // it's parent is the leaf node
						
						parent->leftChild = newNode; //inserts into the proper position
						return;
					}
				} else {
					
					current = current->rightChild;
					if(current == NULL) {
						parent->rightChild = newNode;
						return;
					}
					
				}
				
			}
			
			
			
		}


}
bool binarySearchTree::remove(int key){



}
void binarySearchTree::displayTree(){

    displayTreeHelper(root);

}
void binarySearchTree::displayTreeHelper(bstNode *current){

    		//bstNode currentNode = current;
            
            if(current!=NULL) {
			
			if(current->leftChild !=NULL) { // if left one is pointing to something
				
				//recursively call displaytreeprivate
				displayTreeHelper(current->leftChild);
			}
			
			//print contents of node
			std::cout << current->key <<"\n";
			
			if(current->rightChild!=NULL) {
				
				//recursively call displaytreeprivate
				displayTreeHelper(current->rightChild);
				
			}
			
		}
		else {
			
			std::cout << "Tree is empty";
		}
		

}
void binarySearchTree::genDataS1(){

	for(int i = 1; i<=100; i++){
		insert(i);

	}



}
void binarySearchTree::genDataS2(){
 std::vector<int> numbers;

    for(int i=1; i<=100; i++)       // add 1-100 to the vector
        numbers.push_back(i);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    for(int i=0; i<100; i++)        // print the first 100 randomly sorted numbers
        {
            //std::cout << numbers[i] << std::endl;
            int num = numbers[i];
            insert(num);
        

        }


}

int binarySearchTree::printHeightHelper(bstNode *node){

	bstNode *current = node;

    if (current == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = printHeightHelper(current->leftChild);  
        int rDepth = printHeightHelper(current->rightChild);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  

}
int binarySearchTree::printHeight(){

	return (printHeightHelper(root));

}