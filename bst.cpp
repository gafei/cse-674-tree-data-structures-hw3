#include <iostream>
#include <vector>
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
void binarySearchTree::displayTreeHelper(bstNode *&current){

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
