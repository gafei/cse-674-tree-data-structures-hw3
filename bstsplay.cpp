#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "bstsplay.h"

bstSplayNode* bstSplay::newNode(int key){

    bstSplayNode *newNode = new bstSplayNode();
    newNode->key = key;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return(newNode); 

}
bstSplayNode* bstSplay::rotateRight(bstSplayNode *inputNode){

    bstSplayNode *node = inputNode->leftChild;
    inputNode->leftChild = node->rightChild;
    node->rightChild = inputNode;

    return node;

}
bstSplayNode* bstSplay::rotateLeft(bstSplayNode *inputNode){

    bstSplayNode *node = inputNode->rightChild;
    inputNode->rightChild = node->leftChild;
    node->leftChild = inputNode;

    return node;

}
bstSplayNode* bstSplay::splay(bstSplayNode * root, int key){

    // Base cases: root is NULL or  
    // key is present at root  
    if (root == NULL || root->key == key)  
        return root;  
  
    // Key lies in left subtree  
    if (root->key > key)  
    {  
        // Key is not in tree, we are done  
        if (root->leftChild == NULL) return root;  
  
        // Zig-Zig (Left Left)  
        if (root->leftChild->key > key)  
        {  
            // First recursively bring the 
            // key as root of left-left  
            root->leftChild->leftChild = splay(root->leftChild->leftChild, key);  
  
            // Do first rotation for root,  
            // second rotation is done after else  
            root = rotateRight(root);  
        }  
        else if (root->leftChild->key < key) // Zig-Zag (Left Right)  
        {  
            // First recursively bring  
            // the key as root of left-right  
            root->leftChild->rightChild = splay(root->leftChild->rightChild, key);  
  
            // Do first rotation for root->left  
            if (root->leftChild->rightChild != NULL)  
                root->leftChild = rotateLeft(root->leftChild);  
        }  
  
        // Do second rotation for root  
        return (root->leftChild == NULL)? root: rotateRight(root);  
    }  
    else // Key lies in right subtree  
    {  
        // Key is not in tree, we are done  
        if (root->rightChild == NULL) return root;  
  
        // Zig-Zag (Right Left)  
        if (root->rightChild->key > key)  
        {  
            // Bring the key as root of right-left  
            root->rightChild->leftChild = splay(root->rightChild->leftChild, key);  
  
            // Do first rotation for root->right  
            if (root->rightChild->leftChild != NULL)  
                root->rightChild = rotateRight(root->rightChild);  
        }  
        else if (root->rightChild->key < key)// Zag-Zag (Right Right)  
        {  
            // Bring the key as root of  
            // right-right and do first rotation  
            root->rightChild->rightChild = splay(root->rightChild->rightChild, key);  
            root = rotateLeft(root);  
        }  
  
        // Do second rotation for root  
        return (root->rightChild == NULL)? root: rotateLeft(root);  
    }  

}

bstSplayNode* bstSplay::insert(bstSplayNode *root, int key){

// Simple Case: If tree is empty  
    if (root == NULL) 
        return newNode(key);  
  
    // Bring the closest leaf node to root  
    root = splay(root, key);  
  
    // If key is already present, then return  
    if (root->key == key) return root;  
  
    // Otherwise allocate memory for new node  
    bstSplayNode* newnode = newNode(key);  
  
    // If root's key is greater, make  
    // root as right child of newnode  
    // and copy the left child of root to newnode  
    if (root->key > key)  
    {  
        newnode->rightChild = root;  
        newnode->leftChild = root->leftChild;  
        root->leftChild = NULL;  
    }  
  
    // If root's key is smaller, make  
    // root as left child of newnode  
    // and copy the right child of root to newnode  
    else
    {  
        newnode->leftChild = root;  
        newnode->rightChild = root->rightChild;  
        root->rightChild = NULL;  
    }  
  
    return newnode; // newnode becomes new root  


 }
 bstSplayNode* bstSplay::remove(int key) 
{ 

    bstSplayNode *root = this->root;

    bstSplayNode*temp; 
    if (!root) 
        return NULL; 
      
    // Splay the given key     
    root = splay(root, key); 
      
    // If key is not present, then 
    // return root 
    if (key != root->key) 
        return root; 
          
    // If key is present 
    // If left child of root does not exist 
    // make root->right as root    
    if (!root->leftChild) 
    { 
        temp = root; 
        root = root->rightChild; 
    } 
      
    // Else if left child exits 
    else
    { 
        temp = root; 
  
        /*Note: Since key == root->key, 
        so after Splay(key, root->lchild), 
        the tree we get will have no right child tree 
        and maximum node in left subtree will get splayed*/
        // New root 
        root = splay(root->leftChild, key); 
          
        // Make right child of previous root  as 
        // new root's right child 
        root->rightChild = temp->rightChild; 
    } 
      
    // free the previous root node, that is, 
    // the node containing the key 
    free(temp); 
      
    // return root of the new Splay Tree 
    this->root = root; // update root to be the new root.
    return root; 
      
} 
void bstSplay::displayTreeInOrder(){
    
    displayTreeInOrderHelper(root);

}
void bstSplay::displayTreePreOrder(){
    
    displayTreePreOrderHelper(root);
}


void bstSplay::displayTreeInOrderHelper(bstSplayNode *current){
            
        
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
void bstSplay::displayTreePreOrderHelper(bstSplayNode *node){
	
    bstSplayNode *current = node;

	if(node!=NULL){

		std::cout << current->key <<", ";
		displayTreePreOrderHelper(current->leftChild);
		displayTreePreOrderHelper(current->rightChild);

	}
}

void bstSplay::genDataS1(){

	for(int i = 1; i<=100; i++){
		root = insert(root, i);

			if(i % 10 == 0 && i!=0){

				std::cout<<"\n";
				std::cout <<"Splay Binary Search Tree: \n";
				std::cout <<"Tree structure Pre Order after " << i << " insertions \n";
				displayTreePreOrder();
				std::cout <<"\nTree structure In Order after " << i << " insertions \n";
				displayTreeInOrder();
				std::cout <<"\nSplay BST Height after " << i << " insertions: " << printHeight() <<"\n";
			    std::cout<<"\n\n";



		}


	}

}
void bstSplay::genDataS2(){
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

				std::cout <<"Splay Binary Search Tree: \n";
				std::cout <<"Tree structure Pre Order after " << counter << " insertions \n";
				//displayTreePreOrderHelper(root);
                displayTreePreOrder();
				std::cout <<"\nTree structure In Order after " << counter << " insertions \n";
				//displayTreeInOrderHelper(root);
                displayTreeInOrder();
				std::cout <<"\nInitial Splay Height after " << counter << " insertions: " << printHeight() <<"\n";
			    std::cout<<"\n\n";
	
			
			}

        

        }


}
int bstSplay::printHeightHelper(bstSplayNode *node){

	bstSplayNode *current = node;

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
int bstSplay::printHeight(){

	//std::cout <<"Root is: " << root->key <<"\n";
	return (printHeightHelper(root));

}
