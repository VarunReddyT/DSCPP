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
private:
    void printLevel(Node *root, int level);
public:
    Node *root;
    BinaryTree()
    {
        root = NULL;
    }
    Node *Create();
    void PreOrderDisplay(Node *root);
    void PostOrderDisplay(Node *root);
    void InOrderDisplay(Node *root);
    void LevelOrderDisplay(Node *root);
    void DisplayRoot();
    Node * insert(Node *,int);
    int Height(Node *root);
};

int BinaryTree::Height(Node *root)
{
    if (root == NULL){
        return 0;
    }
    int lh = Height(root->left);
    int rh = Height(root->right);
    if (lh > rh){
        return (lh + 1);
    }   
    else{
        return (rh + 1);
    }
}

void BinaryTree::printLevel(Node *root, int level){
    if(root==NULL){
        return;
    }
    else if(level==0){
        cout<<root->data<<" ";
    }
    else if(level>0){
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
    else{
        return;
    }
}


void BinaryTree::LevelOrderDisplay(Node *root)
{
    int height = Height(root);
    for (int i = 0; i < height; i++)
    {
        printLevel(root,i);
        cout << endl;
    }
}

Node * BinaryTree :: Create(){
    
    if(this->root == NULL){
        int data;
        cout << "Enter root : ";
        cin >> data;
        Node * newNode = new Node(data);
        this->root = newNode;
    }
    else{
        cout << "Root already created" << endl;
    }

    return this->root;
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
    // bt.DisplayRoot();

    bt.insert(bt.root,10);
    bt.insert(bt.root,20);
    bt.insert(bt.root,40);
    bt.insert(bt.root,50);

    bt.PreOrderDisplay(bt.root);
    // cout << endl;
    // bt.LevelOrderDisplay(bt.root);
    return 0 ;
}