#include <iostream>
#include <vector>

class bstNode{

    public:
        int key;
        bstNode *left;
        bstNode *right;
    

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