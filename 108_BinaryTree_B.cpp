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

void reverseLevelOrderDisplay(Node * root){
    queue<Node *> queue;
    stack<Node *> stack;

    queue.push(root);
    queue.push(NULL);

    while(!queue.empty()){
        Node * temp = queue.front();
        queue.pop();

        if(temp == NULL){
            if(!queue.empty()){
                queue.push(NULL);
                stack.push(NULL);
            }
        }

        else{
            stack.push(temp);

            if(temp->right){
                queue.push(temp->right);
            }
            if(temp->left){
                queue.push(temp->left);
            }
        }
    }

    while(!stack.empty()){
        if(stack.top() != NULL){
            cout << stack.top()->data << " ";
        }
        else{
            cout << endl;
        }

        stack.pop();
    }
}

void PreOrderDisplay(Node * root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    PreOrderDisplay(root->left);
    PreOrderDisplay(root->right);
}

void PostOrderDisplay(Node * root){
    if(root == NULL){
        return;
    }
    PostOrderDisplay(root->left);
    PostOrderDisplay(root->right);
    cout << root->data << " ";
}

void InOrderDisplay(Node * root){
    if(root == NULL){
        return;
    }

    InOrderDisplay(root->left);
    cout << root->data << " ";
    InOrderDisplay(root->right);
}

int main()
{
    Node * root = NULL;
    cout << "Enter root : "; 
    root = buildTree(root);

    cout << "Level Order Display : " << endl;
    levelOrderDisplay(root);
    
    
    cout << "Reverse Level Order Display : " << endl;
    reverseLevelOrderDisplay(root);
    cout << endl;

    cout << "Pre Order Display : "<<endl;
    PreOrderDisplay(root);
    cout << endl;

    cout << "In Order Display : " << endl;
    InOrderDisplay(root);
    cout << endl;

    cout << "Post Order Display : " << endl;
    PostOrderDisplay(root);
    cout << endl;

    cout << "Height of the tree : ";
    cout << height(root,1) << endl;
    return 0 ;
}