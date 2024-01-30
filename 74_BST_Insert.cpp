#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node * left;
        Node * right;
        Node(int data){
            this->data = data;
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
        Node * Create();
        void DisplayRoot();
        Node * insert(Node *,int);
        void PreOrderDisplay(Node *);
};

Node * BinaryTree :: Create(){
    int data;

    cout << "Enter data (-1 for NULL) : ";
    cin >> data;

    if(data == -1){
        return NULL;
    }
    Node * newNode = new Node(data);
    // cout << "Enter left child of " << data << endl;
    // newNode->left = Create();
    // cout << "Enter right child of " << data << endl;
    // newNode->right = Create();

    return newNode;
}

void BinaryTree :: DisplayRoot(){
    if(root != NULL){
        cout << "Root is : " << root->data << endl;
        return;
    }
    cout << "No tree created" << endl;
}

Node * BinaryTree :: insert(Node * root, int val){
    Node * new_node;
    if(root == NULL){
        new_node = new Node(val);
        return new_node;
    }
    else if(val < root->data){
        root->left = insert(root->left,val);
    }
    else if(val > root->data){
        root->right = insert(root->right,val);
    }
    else{
        cout << "Inserted Value = Root value" << endl;
    }
    return root;

}

void BinaryTree :: PreOrderDisplay(Node * root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    PreOrderDisplay(root->left);
    PreOrderDisplay(root->right);
}

int main()
{
    BinaryTree bt;
    bt.root = bt.Create();
    bt.DisplayRoot();

    bt.insert(bt.root,10);
    bt.insert(bt.root,20);
    bt.insert(bt.root,40);
    bt.insert(bt.root,50);


    bt.PreOrderDisplay(bt.root);
    return 0 ;
}