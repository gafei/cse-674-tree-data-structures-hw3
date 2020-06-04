#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "bstdsw.h"
/****
bstdsw::bstdsw(){

    root=NULL;


}
*****/

bstdsw::~bstdsw(){

    //destrutor
}

void bstdsw::insert(int key){

		bstdswNode *newNode = new bstdswNode(); // init a new node
		newNode->key = key;
		
		if (root == NULL) 
		{
			root = newNode; // if nothing is in the tree, create a newnode
			//newNode->key = key;
		}
		else {
			
			//insert a node into the tree
			
			bstdswNode *current = root; // changes as we go down the binary search tree
			bstdswNode *parent; // this repsrreesnets the parent of the current node
			
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
bool bstdsw::remove(int key){

	// pointer to store parent node of current node
	bstdswNode* parent = nullptr;

	// start with root node
	bstdswNode* curr = root;

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
		bstdswNode *successor  = minimumKey(curr->rightChild);

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
		bstdswNode* child = (curr->leftChild)? curr->leftChild: curr->rightChild;

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
void bstdsw::searchKey(bstdswNode* &curr, int key, bstdswNode* &parent)
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
bstdswNode* bstdsw::minimumKey(bstdswNode* curr)
{
	while (curr->leftChild != nullptr) {
		curr = curr->leftChild;
	}
	return curr;
}

bstdswNode* bstdsw::rotateRight(bstdswNode *& grandParent, bstdswNode *& parent, bstdswNode *& leftChild){

    if(grandParent != NULL){
        grandParent->rightChild = leftChild;
    }
    else{
        root = leftChild;
    }
    parent->leftChild = leftChild->rightChild;
    leftChild->rightChild = parent;

    return grandParent;


}

bstdswNode* bstdsw::rotateLeft(bstdswNode *& inputNode){

   bstdswNode *right, *rightLeft;

   if ((inputNode == NULL) ||(inputNode->rightChild == NULL)) return inputNode;
   
   right = inputNode->rightChild;
   rightLeft = right->leftChild;
   right->leftChild = inputNode; 
   inputNode->rightChild = rightLeft;
   
   return right;



}

void bstdsw::createBackBone(){

    createBackBoneHelper(root);

}


void bstdsw::createBackBoneHelper(bstdswNode *& root){

   bstdswNode *grandParent = nullptr;
   bstdswNode *parent = root;
   bstdswNode *leftChild;
    //while(grandParent !=NULL){
    while(parent !=NULL){
        leftChild = parent->leftChild; // assign leftchild from parent to leftchild
        if(leftChild!=NULL){
            // rotate this child around temp and then set to grandparent
            grandParent = rotateRight(grandParent, parent, leftChild);
            parent = leftChild;

        }else{

            //root->rightChild = tempNode; //set temp to right child
            grandParent = parent;
            parent = parent->rightChild;


        }
        //special case
        if(grandParent == NULL){
            root = leftChild;

        }

    }




}
void bstdsw::createPerfectTree(bstdswNode *&inputNode){

    int height, t, l, lc;

   /* n is the number of nodes in the original tree */
   height = printHeight();

   /* Compute l = log2(n+1) */
   t = height + 1; 
   l = 0;
   while (t > 1) { 
	   ++l; 
	   t /= 2; //compute the new length of the balanced tree
	   }

   /* Create the deepest leaves */
   lc = height + 1 - (1 << l); if (lc == 0) lc = (1 << (l - 1));
   inputNode = compress(inputNode,lc); // this is a left rotate

   height -= lc;
   while (height > 1) { /* Sequence of left rotations */
      height /= 2;
      inputNode = compress(inputNode,height); // keep doing left rotates
   }


}
bstdswNode * bstdsw::compress(bstdswNode *inputNode, int count){

	bstdswNode *temp;
	temp = inputNode;
	
	while (count) {
		temp->rightChild = rotateLeft(temp->rightChild); //performs a left rotate
		temp = temp->rightChild;
		--count;
	}

   return inputNode;
}

void bstdsw::genDataS1(){

	for(int i = 1; i<=100; i++){
		insert(i);

			if(i % 10 == 0 && i!=0){

				std::cout<<"\n";
                std::cout <<"Initial "; // Original root is:
                printRoot();
				
				std::cout <<"Initial BST: \n";
				std::cout <<"Tree structure Pre Order after " << i << " insertions \n";
				displayTreePreOrder();
				std::cout <<"\nTree structure In Order after " << i << " insertions \n";
				displayTreeInOrder();
				std::cout <<"\nInitial BST Height after " << i << " insertions: " << printHeight() <<"\n";

				std::cout <<"\n\nRight Skewed Tree: \n";
                std::cout <<"Creating backbone after " << i << " insertions: \n";
                createBackBone(); // should only have right children and NO left children, asecnding order.
                std::cout << "New "; // New root is
                printRoot();
				std::cout <<"Backbone Tree structure Pre Order after " << i << " insertions \n";
				displayTreePreOrder();
				std::cout <<"\nBackbone Tree structure In Order after " << i << " insertions \n";
                displayTreeInOrder();
				std::cout <<"\nBackbone Height after " << i << " insertions: " << printHeight() <<"\n";
				//std::cout<<"\n\n";

				std::cout <<"\n\nBalanced Tree: \n";
                std::cout <<"Creating perfect tree after " << i << " insertions: \n";
                createPerfectTree(root);
                std::cout << "Perfect Tree "; // Perfect Tree root is
                printRoot();
            
                //std::cout << "Height after DSW: " << printHeight() << "\n";

				std::cout <<"Balanced Tree structure Pre Order after " << i << " insertions \n";
				displayTreePreOrder();
				std::cout <<"\nBalanced Tree structure In Order after " << i << " insertions \n";
                displayTreeInOrder();
				std::cout <<"\nBalanced Tree Height after " << i << " insertions: " << printHeight() <<"\n";
               
			   std::cout<<"\n\n";



		}


	}

}
void bstdsw::genDataS2(){
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
                std::cout <<"Initial "; // Original root is:
                printRoot();
				
				std::cout <<"Initial BST: \n";
				std::cout <<"Tree structure Pre Order after " << counter << " insertions \n";
				displayTreePreOrder();
				std::cout <<"\nTree structure In Order after " << counter << " insertions \n";
				displayTreeInOrder();
				std::cout <<"\nInitial BST Height after " << counter << " insertions: " << printHeight() <<"\n";

				std::cout <<"\n\nRight Skewed Tree: \n";
                std::cout <<"Creating backbone after " << counter << " insertions: \n";
                createBackBone(); // should only have right children and NO left children, asecnding order.
                std::cout << "New "; // New root is
                printRoot();
				std::cout <<"Backbone Tree structure Pre Order after " << counter << " insertions \n";
				displayTreePreOrder();
				std::cout <<"\nBackbone Tree structure In Order after " << counter << " insertions \n";
                displayTreeInOrder();
				std::cout <<"\nBackbone Height after " << counter << " insertions: " << printHeight() <<"\n";
				//std::cout<<"\n\n";

				std::cout <<"\n\nBalanced Tree: \n";
                std::cout <<"Creating perfect tree after " << counter << " insertions: \n";
                createPerfectTree(root);
                std::cout << "Perfect Tree "; // Perfect Tree root is
                printRoot();
            
                //std::cout << "Height after DSW: " << printHeight() << "\n";

				std::cout <<"Balanced Tree structure Pre Order after " << counter << " insertions \n";
				displayTreePreOrder();
				std::cout <<"\nBalanced Tree structure In Order after " << counter << " insertions \n";
                displayTreeInOrder();
				std::cout <<"\nBalanced Tree Height after " << counter << " insertions: " << printHeight() <<"\n";
               
			   std::cout<<"\n\n";
			   // displayTreeInOrder();
				//std::cout<<"\n";
			
			}

        

        }


}

void bstdsw::displayTreeInOrder(){

    displayTreeInOrderHelper(root);

}
void bstdsw::displayTreeInOrderHelper(bstdswNode *current){

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
void bstdsw::displayTreePreOrderHelper(bstdswNode *node){

	bstdswNode *current = node;

	if(node!=NULL){

		std::cout << current->key <<", ";
		displayTreePreOrderHelper(current->leftChild);
		displayTreePreOrderHelper(current->rightChild);

	}

}
void bstdsw::displayTreePreOrder(){
	
		displayTreePreOrderHelper(root);
}



int bstdsw::printHeightHelper(bstdswNode *node){

	bstdswNode *current = node;

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
int bstdsw::printHeight(){

	//std::cout <<"Root is: " << root->key <<"\n";
	return (printHeightHelper(root));

}

void bstdsw::printRoot(){
    std::cout <<"Root is: " << root->key <<"\n";
    
}

