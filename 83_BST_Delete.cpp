// ! Deletion
// * Case 1 : The node is a leaf node
// * Case 2 : The node is a non-leaf node
// * Case 3 : The node is a root node

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

class BinarySearchTree{
private:
    void printLevel(Node *root, int level);
public:
    Node *root;
    BinarySearchTree()
    {
        root = NULL;
    }
    Node *Create();
    void InOrderDisplay(Node *root);
    void LevelOrderDisplay(Node *root);
    void DisplayRoot();
    Node * insert(Node *,int);
    Node * deleteNode(Node *,int);
    int Height(Node *root);
};

int BinarySearchTree::Height(Node *root)
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

void BinarySearchTree::printLevel(Node *root, int level){
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


void BinarySearchTree::LevelOrderDisplay(Node *root)
{
    int height = Height(root);
    for (int i = 0; i < height; i++)
    {
        printLevel(root,i);
        cout << endl;
    }
}

Node * BinarySearchTree :: Create(){
    
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

void BinarySearchTree :: DisplayRoot(){
    if(root != NULL){
        cout << "Root is : " << root->data << endl;
        return;
    }
    cout << "No tree created" << endl;
}

Node * BinarySearchTree :: insert(Node * root, int val){
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

void BinarySearchTree :: InOrderDisplay(Node * root){
    if(root == NULL){
        return;
    }
    InOrderDisplay(root->left);
    cout << root->data << " ";
    InOrderDisplay(root->right);
}

Node * BinarySearchTree :: deleteNode(Node * root, int val){


    // * Traversal

    if(root == NULL){
        return root;
    }
    else if(val < root->data){
        root->left = deleteNode(root->left,val);
        return root;
    }
    else if(val > root->data){
        root->right = deleteNode(root->right,val);
        return root;
    }


    // * If 0 or 1 child

    if(root->left == NULL){
        Node * temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == NULL){
        Node * temp = root->left;
        delete root;
        return temp;
    }
    
    // * 2 children

    else{
        Node * tempParent = root;
        Node * temp = root->right;
        while(temp->left != NULL){
            tempParent = temp;
            temp = temp->left;
        }

        int data = temp->data;
        tempParent->left = NULL;
        root->data = data;
        delete temp;
        return root;
    }
}

int main()
{
    BinarySearchTree bt;
    bt.root = bt.Create();
    // bt.DisplayRoot();

    bt.insert(bt.root,10);
    bt.insert(bt.root,20);
    bt.insert(bt.root,40);
    bt.insert(bt.root,50);

    bt.InOrderDisplay(bt.root);
    cout << endl;
    bt.LevelOrderDisplay(bt.root);

    bt.deleteNode(bt.root,20);
    
    bt.InOrderDisplay(bt.root);
    cout << endl;
    bt.LevelOrderDisplay(bt.root);
    return 0 ;
}