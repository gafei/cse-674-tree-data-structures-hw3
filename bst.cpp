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

	// pointer to store parent node of current node
	bstNode* parent = nullptr;

	// start with root node
	bstNode* curr = root;

	// search key in BST and set its parent pointer
	searchKey(curr, key, parent);

	// return if key is not found in the tree
	if (curr == nullptr)
		return false;

	// Case 1: node to be deleted has no children i.e. it is a leaf node
	if (curr->leftChild == nullptr && curr->rightChild == nullptr)
	{
		// if node to be deleted is not a root node, then set its
		// parent left/right child to null
		if (curr != root)
		{
			if (parent->leftChild == curr)
				parent->leftChild = nullptr;
			else
				parent->rightChild = nullptr;
		}
		// if tree has only root node, delete it and set root to null
		else
			root = nullptr;

		// deallocate the memory
		free(curr);	 // or delete curr;
	}

	// Case 2: node to be deleted has two children
	else if (curr->leftChild && curr->rightChild)
	{
		// find its in-order successor node
		bstNode* successor  = minimumKey(curr->rightChild);

		// store successor value
		int val = successor->key;

		// recursively delete the successor. Note that the successor
		// will have at-most one child (right child)
		remove(successor->key);

		// Copy the value of successor to current node
		curr->key = val;
	}

	// Case 3: node to be deleted has only one child
	else
	{
		// find child node
		bstNode* child = (curr->leftChild)? curr->leftChild: curr->rightChild;

		// if node to be deleted is not a root node, then set its parent
		// to its child
		if (curr != root)
		{
			if (curr == parent->leftChild)
				parent->leftChild = child;
			else
				parent->rightChild = child;
		}

		// if node to be deleted is root node, then set the root to child
		else
			root = child;

		// deallocate the memory
		free(curr);
	}
	return true;

}
void binarySearchTree::searchKey(bstNode* &curr, int key, bstNode* &parent)
{
	// traverse the tree and search for the key
	while (curr != nullptr && curr->key != key)
	{
		// update parent node as current node
		parent = curr;

		// if given key is less than the current node, go to left subtree
		// else go to right subtree
		if (key < curr->key)
			curr = curr->leftChild;
		else
			curr = curr->rightChild;
	}
}
bstNode* binarySearchTree::minimumKey(bstNode* curr)
{
	while (curr->leftChild != nullptr) {
		curr = curr->leftChild;
	}
	return curr;
}


/*******************
bool binarySearchTree::remove(int key){

		// 3 main steps in here
		
		bstNode *currentNode = root;
		bstNode *parentNode = root; // parent of 'currentNode'
		
		bool isLeftChild = false; //flag to determine if it's a left or right child
		
		// Searching to find the node with the key to delete
		while(currentNode->key !=key) {
			
			//assign parentnode to currentnode
			
			parentNode = currentNode;
			
			if(key < currentNode->key) {
				
				isLeftChild = true;
				currentNode = currentNode->leftChild; //keep searching  
				
			}else{
				
				currentNode = currentNode->rightChild; // this is a right child 
				isLeftChild = false;
				
			}
			
			if(currentNode == NULL) {
				return false;
			}
			
			
		}
		
		// found the node that you want to delete
		
		
		// make nodetoDelete 'currentnode'. Since currentnode was used to 
		// traverse through the array, we're giving it a new node name now
		
		bstNode *nodetoDelete = currentNode; 
		
		// check if node is a leaf node (node with no children)
		// assign parent's child attribute to null;
		
		if(nodetoDelete->leftChild == NULL && nodetoDelete->rightChild == NULL)
		{
			// that means there's no children here.
			// change the child reference to be a node
			
			if(nodetoDelete == root) {
				
				root = NULL;
			}
			
			else if(isLeftChild) {
				parentNode->leftChild = NULL;
				
			}
			else {
				parentNode->rightChild = NULL;
			}
			
			
		} // if node has one child that is on the left
		else if(nodetoDelete->rightChild == NULL) {
			
			if(nodetoDelete ==root) {
				root = nodetoDelete->leftChild;
			}
			else if (isLeftChild) {
				parentNode->leftChild = nodetoDelete->leftChild;
			}
			else {
				parentNode->rightChild = nodetoDelete->leftChild;
			}
			
		}
		// if node has one child that is on the right
		else if(nodetoDelete->leftChild == NULL) {
			
			if(nodetoDelete ==root) {
				root = nodetoDelete->rightChild;
			}
			else if (isLeftChild) {
				parentNode->leftChild = nodetoDelete->rightChild;
			}
			else {
				parentNode->rightChild = nodetoDelete->rightChild;
			}
		
		}
		
		
		// check if node is a child (at least one)
		// copy the subtree to the leading node's position
		
		// check if node has two children
		
		else {
			
			// find the smallest of the set of nodes
			// that are larger/replace the number you're deleting
			
			// get successor of the node
			
			
			// sucessor is the min value out of the set of values
			// that is LARGER than the node that we're trying to delete
			bstNode successor = getSuccessor(nodetoDelete);
			
			// find min value to delete
			// connect parent of the nodetodelete with the sucessor instead
			
			if(nodetoDelete == root) {
				
				root = &successor;
				
			}else if(isLeftChild){
				
				parentNode->leftChild = &successor;
			}
			else {
				
				parentNode->rightChild = &successor;
			}
			
			successor.leftChild = nodetoDelete->leftChild;
			
		}
		//free your pointer
		free(currentNode);
		//free(nodetoDelete);
		//free(parentNode);
		return true; // if able to delete



}
**************/
void binarySearchTree::displayTreeInOrder(){

    displayTreeHelperInOrder(root);

}
void binarySearchTree::displayTreeHelperInOrder(bstNode *current){

    		//bstNode currentNode = current;
        
            if(current!=NULL) {
			
				if(current->leftChild !=NULL) { // if left one is pointing to something
					
					//recursively call displaytreehelperinorder
					displayTreeHelperInOrder(current->leftChild);
				}
			
				//print contents of node
				if(current->key ==100)
				{
					std::cout << current->key <<"";
				}
				else{
					std::cout << current->key <<", ";	
				}
				//std::cout << current->key <<", ";
				
				if(current->rightChild!=NULL) {
					
					//recursively call displaytreehelperinorder
					displayTreeHelperInOrder(current->rightChild);
					
				}
			
		}
		else {
			
			std::cout << "Tree is empty";
		}
		

}
void binarySearchTree::genDataS1(){

	for(int i = 1; i<=100; i++){
		insert(i);

			if(i % 10 == 0 && i!=0){
			
			std::cout<<"\n";
			std::cout <<"Height after " << i << " insertions: " << printHeight() <<"\n";
			std::cout <<"Tree structure after " << i << " insertions \n";
			displayTreeInOrder();
			std::cout<<"\n";

		}


	}

}
void binarySearchTree::genDataS2(){
 std::vector<int> numbers;

    for(int i=1; i<=100; i++)       // add 1-100 to the vector
        numbers.push_back(i);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

	int counter =0;
    for(int i=0; i<100; i++)        // print the first 100 randomly sorted numbers in index 0-99
        {
            //std::cout << numbers[i] << std::endl;

            int num = numbers[i];
            insert(num);
			counter++;
		
			if(counter % 10 == 0 ){ //&& i!=0
				std::cout<<"\n";
				std::cout <<"Height after " << counter << " insertions: " << printHeight() <<"\n";
				std::cout <<"Tree structure after " << counter << " insertions \n";
				displayTreeInOrder();
				std::cout<<"\n";
			
			}

        

        }


}

int binarySearchTree::printHeightHelper(bstNode *node){

	bstNode *current = node;

    //if (current == NULL)
	if (current == NULL || (current->leftChild==NULL 
		&& current->rightChild==NULL)) { //or current = 0x01? // or current->leftC
		return 0;
	}
	
	      
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

	//std::cout <<"Root is: " << root->key <<"\n";
	return (printHeightHelper(root));

}
bstNode & binarySearchTree::getSuccessor(bstNode *nodetoDelete){
		
		bstNode *successorParent = nodetoDelete;
		bstNode *successor = nodetoDelete;
		bstNode *current = nodetoDelete->rightChild;
		
		while(current!=NULL) { //start going down tree until node has no left child
			
			successorParent = successor;
			successor = current;
			current = current->leftChild;
			
		}
		
		// if successor is not a right child
		if(successor!= nodetoDelete->rightChild) {
			
			successorParent->leftChild = successor->rightChild;
			successor->rightChild = nodetoDelete->rightChild;
			
		}
		
		return *successor;
}


void binarySearchTree::binaryInsert(int key){

}

bool binarySearchTree::binaryRemove(int key){

}