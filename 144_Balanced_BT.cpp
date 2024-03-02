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
        bool isBalanced(Node * root){
            if(root == NULL){
                return true;
            }

            bool left = isBalanced(root->left);
            bool right = isBalanced(root->right);

            bool diff = abs(height(root->left) - height(root->right)) <=1;

            if(left && right && diff){
                return true;    
            }
            else{
                return false;
            }
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

    if(bt.isBalanced(bt.root) == 1){
        cout << "Tree is balanced";
    }
    else{
        cout << "Tree is unbalanced";
    }


    return 0;
}