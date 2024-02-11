#include<iostream>
#include<queue>
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
    queue<Node *> queue;
    queue.push(root);
    queue.push(NULL);

    while(!queue.empty()){
        Node * temp = queue.front();
        queue.pop();
        if(temp == NULL){
            cout << endl;
            if(!queue.empty()){
                queue.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                queue.push(temp->left);
            }
            if(temp->right){
                queue.push(temp->right);
            }
        }
    }
}

int height(Node * root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;

    return ans;
}

int main()
{
    Node * root = NULL;
    cout << "Enter root : ";
    root = buildTree(root);

    cout << "Level Order Display" << endl;
    levelOrderDisplay(root);

    cout << "Height : " << height(root) << endl;

    return 0 ;
}