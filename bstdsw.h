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

        bstdswNode findMin();
        bstdswNode findMax();
        void displayTreeInOrder(); 
        void genDataS1();
        void genDataS2();
        int printHeight();



};