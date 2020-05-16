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



    private:
        bstNode *root;

};