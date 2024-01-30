#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node*right;
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
        Node * create();
        void DisplayRoot();
        void PreOrderDisplay(Node*);
        void PostOrderDisplay(Node*);
        void InOrderDisplay(Node*);
        int Height(Node * root);
};

Node * BinaryTree :: create(){
    int data;
    cout << "Enter data (-1 for NULL) : " ;
    cin >> data;
    if(data == -1){
        return NULL;
    }

    Node * new_node = new Node(data);

    cout << "Enter left child of " << data << " : " << endl;
    new_node->left = create();
    cout << "Enter right child of " << data << " : " << endl;
    new_node->right = create();

    return new_node;
}

void BinaryTree :: DisplayRoot(){  // Only root of the tree
    if(root != NULL){
        cout << "Root of the binary tree is : " << root->data << endl;
    }
}

void BinaryTree :: PreOrderDisplay(Node * root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    PreOrderDisplay(root->left);
    PreOrderDisplay(root->right);
}

void BinaryTree :: PostOrderDisplay(Node * root){
    if(root == NULL){
        return;
    }
    PostOrderDisplay(root->left);
    PostOrderDisplay(root->right);
    cout << root->data << " ";
}

void BinaryTree :: InOrderDisplay(Node * root){
    if(root == NULL){
        return;
    }

    InOrderDisplay(root->left);
    cout << root->data << " ";
    InOrderDisplay(root->right);
}

int BinaryTree :: Height(Node * root){
    if(root == NULL){
        return 0;
    }

    int left_height = Height(root->left);
    int right_height = Height(root->right);

    if(left_height > right_height){
        return(left_height+1);
    }
    else{
        return(right_height+1);
    }
}

int main()
{
    BinaryTree bt;
    bt.root = bt.create();
    bt.DisplayRoot();

    cout << "Pre Order Display : " << endl;
    bt.PreOrderDisplay(bt.root);
    cout << endl;

    cout << "Post Order Display : " << endl;
    bt.PostOrderDisplay(bt.root);
    cout << endl;

    cout << "In Order Display : " << endl;
    bt.InOrderDisplay(bt.root);
    cout << endl;
    return 0 ;
}