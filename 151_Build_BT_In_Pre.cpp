#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

        int height(Node * root){
            if(root == NULL){
                return 0;
            }
            int left = height(root->left);
            int right = height(root->right);
            int ans = max(left,right) + 1;
            return ans;
        }

        void printLevel(Node * root, int i){
            if(root == NULL){
                return;
            }
            else if(i == 0){
                cout << root->val << " ";
            }
            else if(i>0){
                printLevel(root->left,i-1);
                printLevel(root->right,i-1);
            }
        }
        void levelOrderDisplay(Node * root){
            int h = height(root);
            for(int i = 0; i<h; i++){
                printLevel(root,i);
                cout << endl;
            }
        }
        int findPos(int inorder[], int element, int n){
            for(int i = 0; i<n; i++){
                if(inorder[i] == element){
                    return i;
                }
            }
            return -1;
        }
        // void createMapping(int inorder[],map<int,int>&nodeToIndex, int n){
        //     for(int i = 0; i<n; i++){
        //         nodeToIndex[inorder[i]] = i; 
        //     }
        // }
        Node * solve(int inorder[],int preorder[],int &index, int inorderStart, int inorderEnd, int n){
            if(index >= n || inorderStart > inorderEnd){
                return NULL;
            }
            int element = preorder[index++];
            Node * root = new Node(element);
            int pos = findPos(inorder,element,n);
            // int pos = nodeToIndex[element];
            root->left = solve(inorder,preorder,index,inorderStart,pos-1,n);
            root->right = solve(inorder,preorder,index,pos+1,inorderEnd,n);
            return root;    

        }
        Node * buildTree(int inorder[],int preorder[],int n){
            int preOrderIndex = 0; // Root index
            // map<int,int> nodeToIndex;
            Node * res = solve(inorder,preorder,preOrderIndex,0,n-1,n);
            return res;
        }
};

int main()
{
    BinaryTree bt;
    int inorder[] = {9,3,15,20,7};
    int preorder[] = {3,9,20,15,7};
    int n = 5;
    bt.root = bt.buildTree(inorder,preorder,n);

    bt.levelOrderDisplay(bt.root);
    return 0;
}