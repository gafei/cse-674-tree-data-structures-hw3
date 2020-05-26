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

        bstNode findMin();
        bstNode findMax();
        void displayTree(); 
        void genDataS1();
        void genDataS2();
        int printHeight();
       
        void binaryInsert(int key);
        bool binaryRemove(int key);

        


    private:
        bstNode *root;
        void displayTreeHelper(bstNode *current);
        int printHeightHelper(bstNode *node);

        bstNode & getSuccessor(bstNode *nodetoDelete);



};