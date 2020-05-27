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

        bstNode findMin();
        bstNode findMax();
        void displayTreeInOrder(); 
        void genDataS1();
        void genDataS2();
        int printHeight();
       
        void binaryInsert(int key);
        bool binaryRemove(int key);

        


    private:
        bstNode *root;
        void displayTreeHelperInOrder(bstNode *current);
        int printHeightHelper(bstNode *node);

        bstNode & getSuccessor(bstNode *nodetoDelete);



};