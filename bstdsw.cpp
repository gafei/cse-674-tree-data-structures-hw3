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
/********
bstdswNode* bstdsw::rotateLeft(bstdswNode *& grandParent, bstdswNode *& parent, bstdswNode *& rightChild){

    if(grandParent != NULL){
        grandParent->rightChild = rightChild;
    }
    else{
        root = rightChild;
    }
    parent->rightChild = rightChild->leftChild;
    rightChild->leftChild = parent;

    return grandParent;


}
**************/
void bstdsw::rotateLeft(bstdswNode *& grandParent){

        if(!grandParent) return;
        bstdswNode *par = grandParent->rightChild;
        if(!par)return;
        bstdswNode *ch  = par->rightChild;
        grandParent->rightChild=par->leftChild;
        par->leftChild=grandParent;
        grandParent = par;

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
void bstdsw::createPerfectTree(int counter){
/***************
    int n =0;
    bstdswNode *temp = root;
    
    for (temp; temp!=NULL; temp = temp->rightChild){

        n++; // counts nodes

    }
    //m = 2^floor[lg(n+1)]-1, ie the greatest power of 2 less than n: minus 1
    int m = greatestPowerOf2LessThanN(n + 1) - 1;
    makeRotations(n - m);
    
    while (m > 1) {
        makeRotations(m /= 2);
    }
***********************/
    //int n = size ; // hardcoded for 10 for now
    //int n = 10;
    //int size = 10;
    int n = size = counter;
    int m = (1<<((int)(log10(n+1)/log10(2))))-1;
        int i;
        bstdswNode *Gr=0,*tmp;
        if(size<3)return;printf("%d\n",m);
        for(i=0,Gr=root;i<n-m;i++){
            if(i==0){
    
                Gr = Gr->rightChild;
                rotateLeft(root);  
            }else if(Gr&&Gr->rightChild){
                
                tmp = Gr->rightChild->rightChild;
                rotateLeft(Gr->rightChild);
                Gr = tmp;
            }
        }
        while(m>1){
            m = m/2;
            for(i=0,Gr=root;i<m;i++){
                if(i==0){
                    Gr = Gr->rightChild;
                    rotateLeft(root);
                }else if(Gr&&Gr->rightChild){
                    tmp = Gr->rightChild->rightChild;
                    rotateLeft(Gr->rightChild);
                    Gr = tmp;
                }
            }
        }




}

int bstdsw::greatestPowerOf2LessThanN(int n) {
  int x = MSB(n);//MSB
  return (1 << x);//2^x
}
 
/**
 * Time complexity: log(n)
 * return the index of most significant set bit: index of
 * least significant bit is 0
 */
int bstdsw::MSB(int n) {
  int ndx = 0;
  while (1 < n) {
    n = (n >> 1);
    ndx++;
  }
  return ndx;
}
void bstdsw::makeRotations(int bound) {
  
  bstdswNode *grandParent = NULL;
  bstdswNode *parent = root;
  bstdswNode *child = root->rightChild;
  
  for (; bound > 0; bound--) {
      if (child != NULL) {
       // rotateLeft(grandParent, parent, child);
        grandParent = child;
        parent = grandParent->rightChild;
        if(grandParent->rightChild){
            child = parent->rightChild;
        }
        else{
            std::cout <<"No grandparent with a rightchild\n";
            break; }
        
      } 
      else {
          std::cout << "Couldn't perform rotations\n";
        break;
      }
    }
}
 




void bstdsw::genDataS1(){

	for(int i = 1; i<=100; i++){
		insert(i);

			if(i % 10 == 0 && i!=0){
			
			std::cout<<"\n";
			std::cout <<"Height after " << i << " insertions: " << printHeight() <<"\n";
			std::cout <<"Tree structure after " << i << " insertions \n";
			displayTreeInOrder();

            std::cout <<"\nRunning DSW algorithm after " << i << " insertions: \n";
            createBackBone();
            std::cout << printHeight() << "\n";

			std::cout<<"\n";

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
                std::cout <<"Original "; // Original root is:
                printRoot();

				std::cout <<"Height after " << counter << " insertions: " << printHeight() <<"\n";
				std::cout <<"Tree structure after " << counter << " insertions \n";
				displayTreeInOrder();

                std::cout <<"\nCreating backbone after " << counter << " insertions: \n";
                createBackBone(); // should only have right children and NO left children, asecnding order.
                std::cout << "New "; // New root is
                printRoot();
                displayTreeInOrder();
				std::cout<<"\n";

                std::cout <<"\nCreating perfect tree after " << counter << " insertions: \n";
                createPerfectTree(counter);
                std::cout << "Perfect Tree "; // Perfect Tree root is
                printRoot();
            
                std::cout << "Height after DSW: " << printHeight() << "\n";
                displayTreeInOrder();
				std::cout<<"\n";
			
			}

        

        }


}

void bstdsw::displayTreeInOrder(){

    displayTreeHelperInOrder(root);

}
void bstdsw::displayTreeHelperInOrder(bstdswNode *current){

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
int bstdsw::printHeightHelper(bstdswNode *node){

	bstdswNode *current = node;

    //if (current == NULL)
	if (current == NULL || (current->leftChild==NULL 
		&& current->rightChild==NULL)) { //or current = 0x01? // or current->leftC
        // This is an empty tree
		return -1;
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
int bstdsw::printHeight(){

	//std::cout <<"Root is: " << root->key <<"\n";
	return (printHeightHelper(root));

}

void bstdsw::printRoot(){
    std::cout <<"Root is: " << root->key <<"\n";
    
}

