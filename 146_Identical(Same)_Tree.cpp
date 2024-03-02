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
        bool isIdentical(Node * root1, Node * root2){
            if(root1 == NULL && root2 == NULL){
                return true;
            }
            if(root1 == NULL && root2 != NULL){
                return false;
            }
            if(root1 != NULL && root2 == NULL){
                return false;
            }

            bool left = isIdentical(root1->left,root2->left);
            bool right = isIdentical(root1->right,root2->right);

            // Current Value
            bool value = root1->val == root2->val;

            if(left && right && value){
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
    BinaryTree bt1;
    BinaryTree bt2;

    cout << "Enter root1 : ";
    bt1.root = bt1.create(bt1.root);

    cout << "Enter root2 : ";
    bt2.root = bt2.create(bt2.root);

    if(bt1.isIdentical(bt1.root,bt2.root)){
        cout << "Identical";
    }
    else{
        cout << "Not Identical";
    }
    return 0;
}