#include<iostream>
#include<queue>
#include<stack>
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

Node * buildTree(Node * root){
    int data;
    cin >> data;
    if(data != -1){
        root = new Node(data);
    }
    else{
        return NULL;
    }

    cout << "Enter the left child of " << data << " : ";
    root->left = buildTree(root->left);
    cout << "Enter the right child of " << data << " : ";
    root->right = buildTree(root->right);
    return root;
}

void levelOrderDisplay(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int height(Node * root,int height){
    if(root == NULL){
        cout << "No Tree created" << endl;
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                height++;
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return height;
}

void InOrderDisplay(Node * root,int &count){
    if(root == NULL){
        return;
    }

    InOrderDisplay(root->left,count);

    if(root->left == NULL && root->right == NULL){
        count++;
    }

    InOrderDisplay(root->right,count);
}

int noOfLeafNodes(Node * root){
    int count = 0;

    InOrderDisplay(root,count);

    return count;
}

int main()
{
    Node * root = NULL;
    cout << "Enter root : "; 
    root = buildTree(root);

    cout << "Level Order Display : " << endl;
    levelOrderDisplay(root);

    cout << "Number of leaf nodes in the tree : ";
    cout << noOfLeafNodes(root) << endl;
    return 0 ;
}