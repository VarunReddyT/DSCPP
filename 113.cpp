// * The DeletedNode class is used in the HashMap class to implement lazy deletion. When a node is deleted from the hash table, the node is not actually removed from the table. Instead, it is marked as deleted by setting its key and value members to -1. The DeletedNode class is then used to represent the deleted node. When a new node is inserted into the hash table, the HashMap class first checks to see if there is a deleted node at the desired index. If there is, the new node is inserted into the table at that index, and the deleted node is replaced with a NULL pointer.

#include<iostream>
using namespace std;

const int TABLE_SIZE = 5;

class HashNode{
    public:
        int key;
        int value;
        HashNode(int key,int value){
            this->key = key;
            this->value = value;
        }
};

int main()
{
    
    return 0 ;
}