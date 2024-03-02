// Check whether a tree is balanced or not

#include<iostream>
using namespace std;


class Node{
    public:
        int val;
        Node * left;
        Node * right;
        Node(int data){
            this->val = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinaryTree{
    public:
        Node * root;
        BinaryTree(){
            root = NULL;
        }
        

        Node * create(Node * root){
            int data;
            cin >> data;
            if(data == -1){
                return NULL;
            }
            else{
                root = new Node(data);
            }

            cout << "Enter the left child of " << data << " : ";
            root->left = create(root->left);
            cout << "Enter the right child of " << data << " : ";
            root->right = create(root->right);
            return root;
        }
        
};
int main()
{
    BinaryTree bt;
    cout << "Enter root : ";
    bt.root = bt.create(bt.root);

    
    return 0;
}