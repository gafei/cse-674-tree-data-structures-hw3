#include <iostream>
#include <vector>

class bstSplayNode{

    public:
        int key;
        bstSplayNode *leftChild;
        bstSplayNode *rightChild;


};

class bstSplay{

    public:
        bstSplayNode* newNode(int key);
        bstSplayNode* rotateRight(bstSplayNode *inputNode);
        bstSplayNode* rotateLeft(bstSplayNode *inputNode);
        bstSplayNode* splay(bstSplayNode * root, int key);

        bstSplayNode* insert(bstSplayNode *root, int key);
        //bstSplayNode* remove(bstSplayNode* root, int key); 
        bstSplayNode* remove(int key); 

        //bool remove(int key);
        //void searchKey(bstSplayNode* &curr, int key, bstSplayNode* &parent);
        //bstSplayNode* minimumKey(bstSplayNode* curr);

        void displayTreeInOrder();
        void displayTreePreOrder(); 
        
        void genDataS1();
        void genDataS2();

        int printHeight();

    private:
        bstSplayNode* root;
        
        void displayTreeInOrderHelper(bstSplayNode *current);
        void displayTreePreOrderHelper(bstSplayNode *node);     

        int printHeightHelper(bstSplayNode *node);
};