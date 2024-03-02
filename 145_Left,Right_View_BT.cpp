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
        int height(Node * root){
            if(root == NULL){
                return 0;
            }

            int left = height(root->left);
            int right = height(root->right);

            int ans = max(left,right) + 1;
            return ans;
        }
        void leftTree(Node * root){
            if(root == NULL){
                return;
            }
            cout << root->val << " ";
            leftTree(root->left);
        }

        void rightTree(Node * root){
            if(root == NULL){
                return;
            }
            cout << root->val << " ";
            rightTree(root->right);
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

    cout << "Left View of Tree :" << endl;
    bt.leftTree(bt.root);
    cout << endl;
    cout << "Right View of Tree :" << endl;
    bt.rightTree(bt.root);
    return 0;
}