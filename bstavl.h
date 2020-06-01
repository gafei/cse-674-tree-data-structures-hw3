#include <iostream>
#include <vector>
class bstavlNode{

    public:
        int key;
        bstavlNode *leftChild;
        bstavlNode *rightChild;
        int height;


};

class bstavl{

    public:
        bstavl();
        ~bstavl();

        bstavlNode* insert(bstavlNode *node, int key);
        bool remove(int key);
        void searchKey(bstavlNode* &curr, int key, bstavlNode* &parent);
        bstavlNode* minimumKey(bstavlNode* curr);


        void displayTreeInOrder();
        void displayTreePreOrder(); 
        void genDataS1();
        void genDataS2();
        int printHeight(bstavlNode *inputNode); // gets height of tree
        void printRoot();
        bstavlNode * rotateRight(bstavlNode *rootNode);
        bstavlNode * rotateLeft(bstavlNode *rootNode);
        int getBalance(bstavlNode *inputNode);

    private:
        bstavlNode *root;
        int getMax(int a, int b);

        void displayTreeInOrderHelper(bstavlNode *current);
        void displayTreePreOrderHelper(bstavlNode *current); 
        int printHeightHelper(bstavlNode *node);


        





};