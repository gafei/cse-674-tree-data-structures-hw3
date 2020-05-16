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
		
		if (root == NULL) 
		{
			root = newNode; // if nothing is in the tree, create a newnode
			
		}
		else {
			
			//insert a node into the tree
			
			bstNode *current = root; // changes as we go down the binary search tree
			bstNode *parent; // this repsrreesnets the parent of the current node
			
			while(true) {
				
				parent = current;
				if(key < current->key) {
					current = current.leftChild;
					
					if(current == null) { // it's parent is the leaf node
						
						parent.leftChild = newNode; //inserts into the proper position
						return;
					}
				} else {
					
					current = current.rightChild;
					if(current == null) {
						parent.rightChild = newNode;
						return;
					}
					
				}
				
			}
			
			
			
		}
		



}
bool binarySearchTree::remove(int key){



}
