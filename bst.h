#include <iostream>
#include <vector>

class bstNode{

    public:
        int key;
        bstNode *leftChild;
        bstNode *rightChild;
 

};

class binarySearchTree{

    public:
        binarySearchTree();
        ~binarySearchTree();

        void insert(int key);
        bool remove(int key);
        void searchKey(bstNode* &curr, int key, bstNode* &parent);
        bstNode* minimumKey(bstNode* curr);

       // bstNode findMin();
       // bstNode findMax();
        void displayTreeInOrder(); 
        void displayTreePreOrder();
        void genDataS1();
        void genDataS2();
        int printHeight();
       
        //int binarySearch(std::vector<int> &inputVector, int x);
        //int recursivebinarySearch(std::vector<int> &inputVector, int start, int end, int x);
        

        


    private:
        bstNode *root;
        void displayTreeHelperInOrder(bstNode *current);
        void displayTreePreOrderHelper( bstNode *node);
        int printHeightHelper(bstNode *node);

       // bstNode & getSuccessor(bstNode *nodetoDelete);



};