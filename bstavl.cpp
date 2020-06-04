#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "bstavl.h"

bstavl::bstavl(){

}
bstavl::~bstavl(){

}


bstavlNode* bstavl::newNode(int key){

    bstavlNode *newNode = new bstavlNode();
    newNode->key = key;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->height = 1;

    return(newNode); 

}

bstavlNode* bstavl::rotateRight(bstavlNode *rootNode){

    if(rootNode->leftChild==NULL){
       // std::cout << "No rootNode->leftChild\n";
        return rootNode;
    }

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
    // this is a recursive implementation

    //bstavlNode *node;

    if(node==NULL){
        return(newNode(key));
    }

    if (key < node->key)  
        node->leftChild = insert(node->leftChild, key);  
    else if (key > node->key)  
        node->rightChild = insert(node->rightChild, key);  
    else // Equal keys are not allowed in BST  
        return node;  
  
    /* Update height of this ancestor node */
    node->height = 1 + getMax(printHeight(node->leftChild),  
                        printHeight(node->rightChild));  
  
    /* Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->leftChild->key)  
        return rotateRight(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->rightChild->key)  
        return rotateLeft(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->leftChild->key)  
    {  
        node->leftChild = rotateLeft(node->leftChild);  
        return rotateRight(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->rightChild->key)  
    {  
        node->rightChild = rotateRight(node->rightChild);  
        return rotateLeft(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
} 
bool bstavl::remove(int key){

	// pointer to store parent node of current node
	bstavlNode* parent = nullptr;

	// start with root node
	bstavlNode* curr = root;

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
		bstavlNode *successor  = minimumKey(curr->rightChild);

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
		bstavlNode* child = (curr->leftChild)? curr->leftChild: curr->rightChild;

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
void bstavl::searchKey(bstavlNode* &curr, int key, bstavlNode* &parent)
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
bstavlNode* bstavl::minimumKey(bstavlNode* curr)
{
	while (curr->leftChild != nullptr) {
		curr = curr->leftChild;
	}
	return curr;
}


void bstavl::genDataS1(){

	for(int i = 1; i<=100; i++){
		root = insert(root, i);

			if(i % 10 == 0 && i!=0){

				std::cout<<"\n";
				std::cout <<"AVL Binary Search Tree: \n";
				std::cout <<"Tree structure Pre Order after " << i << " insertions \n";
				displayTreePreOrder();
				std::cout <<"\nTree structure In Order after " << i << " insertions \n";
				displayTreeInOrder();
				std::cout <<"\nAVL BST Height after " << i << " insertions: " << printHeight(root) <<"\n";
			    std::cout<<"\n\n";



		}


	}

}
void bstavl::genDataS2(){
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
            root = insert(root, num);
			counter++;
		
			if(counter % 10 == 0 ){ //&& i!=0

				std::cout <<"AVL Binary Search Tree: \n";
				std::cout <<"Tree structure Pre Order after " << counter << " insertions \n";
				//displayTreePreOrderHelper(root);
                displayTreePreOrder();
				std::cout <<"\nTree structure In Order after " << counter << " insertions \n";
				//displayTreeInOrderHelper(root);
                displayTreeInOrder();
				std::cout <<"\nInitial BST Height after " << counter << " insertions: " << printHeight(root) <<"\n";
			    std::cout<<"\n\n";
	
			
			}

        

        }


}
void bstavl::displayTreePreOrderHelper(bstavlNode *node){

	bstavlNode *current = node;

	if(node!=NULL){

		std::cout << current->key <<", ";
		displayTreePreOrderHelper(current->leftChild);
		displayTreePreOrderHelper(current->rightChild);

	}

}
void bstavl::displayTreePreOrder(){
	
		displayTreePreOrderHelper(root);
}

void bstavl::displayTreeInOrder(){

    displayTreeInOrderHelper(root);

}
void bstavl::displayTreeInOrderHelper(bstavlNode *current){

    		//bstNode currentNode = current;
        
            if(current!=NULL) {
			
				if(current->leftChild !=NULL) { // if left one is pointing to something
					
					//recursively call displaytreehelperinorder
					displayTreeInOrderHelper(current->leftChild);
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
					displayTreeInOrderHelper(current->rightChild);
					
				}
			
		}
		else {
			
			std::cout << "Tree is empty";
		}
		

}
int bstavl::printHeightHelper(bstavlNode *node){

	bstavlNode *current = node;

    //if (current == NULL)
	//if (current == NULL || (current->leftChild==NULL 
	//	&& current->rightChild==NULL)) { //or current = 0x01? // or current->leftC
        if (current == NULL){
		// This is an empty tree
		return -1;
	
	}
	
	      
    else
    {  
       
        int leftHeight = printHeightHelper(current->leftChild);  
        int rightHeight = printHeightHelper(current->rightChild);  
      
	if(leftHeight > rightHeight){
		return (leftHeight + 1);
	}else{
		return (rightHeight +1);
	}


    }

}
int bstavl::printActualHeight(){

	//std::cout <<"Root is: " << root->key <<"\n";
	return (printHeightHelper(root));

}