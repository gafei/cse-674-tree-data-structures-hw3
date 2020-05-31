#include <iostream>
#include <vector>


class bstdswNode{

    public:
        int key;
        bstdswNode *leftChild;
        bstdswNode *rightChild;
        bstdswNode(){
            leftChild =0; rightChild=0;
        }
        bstdswNode(int key1){
            key = key1;
            leftChild=0;
            rightChild=0; 
        }


};

class bstdsw{

    public:
       // bstdsw();
        
        bstdsw(){
            root=0;
            size=0;
        }
        bstdsw(int key){

        root = new bstdswNode(key); 
        size = 1;

    }
        ~bstdsw();

        void insert(int key);
        bool remove(int key);
        void searchKey(bstdswNode* &curr, int key, bstdswNode* &parent);
        bstdswNode* minimumKey(bstdswNode* curr);

        bstdswNode* rotateRight(bstdswNode *& grandParent, bstdswNode *& parent, bstdswNode *& child);
        //bstdswNode* rotateLeft(bstdswNode *& grandParent, bstdswNode *& parent, bstdswNode *& rightChild);
        void rotateLeft(bstdswNode *& grandParent);
        void createBackBone();
        void createPerfectTree(int counter);


        void displayTreeInOrder(); 
        void genDataS1();
        void genDataS2();
        int printHeight();
        void printRoot();

    private:
        bstdswNode *root;
        int size;
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