#include <iostream>
#include <vector>


class bstdswNode{

    public:
        int key;
        bstdswNode *leftChild;
        bstdswNode *rightChild;


};

class bstdsw{

    public:
        bstdsw();
        ~bstdsw();

        void insert(int key);
        bool remove(int key);
        void searchKey(bstdswNode* &curr, int key, bstdswNode* &parent);
        bstdswNode* minimumKey(bstdswNode* curr);

        bstdswNode* rotateRight(bstdswNode *& grandParent, bstdswNode *& parent, bstdswNode *& child);
        bstdswNode* rotateLeft(bstdswNode *& grandParent, bstdswNode *& parent, bstdswNode *& rightChild);
        void createBackBone();
        void createPerfectTree();


        void displayTreeInOrder(); 
        void genDataS1();
        void genDataS2();
        int printHeight();
        void printRoot();

    private:
        bstdswNode *root;
        void createBackBoneHelper(bstdswNode *& root);
        int greatestPowerOf2LessThanN(int n);
        int MSB(int n);
        void makeRotations(int bound);

        void displayTreeHelperInOrder(bstdswNode *current);
        int printHeightHelper(bstdswNode *node);

        bstdswNode & getSuccessor(bstdswNode *nodetoDelete);
        


        //void displayTreeHelperInOrder(bstNode *current);
       // int printHeightHelper(bstNode *node);

       // bstNode & getSuccessor(bstNode *nodetoDelete);


};