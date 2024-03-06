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
        void createMapping(int inorder[],map<int,int>&nodeToIndex, int n){
            for(int i = 0; i<n; i++){
                nodeToIndex[inorder[i]] = i; 
            }
        }
        Node * solve(int inorder[],int postorder[],int &index, int inorderStart, int inorderEnd, int n, map<int,int> nodeToIndex){
            if(index < 0 || inorderStart > inorderEnd){
                return NULL;
            }
            int element = postorder[index--];
            Node * root = new Node(element);
            int pos = nodeToIndex[element];
            // In this part, right side call must be done first
            root->right = solve(inorder,postorder,index,pos+1,inorderEnd,n,nodeToIndex);
            root->left = solve(inorder,postorder,index,inorderStart,pos-1,n,nodeToIndex);
            return root;    

        }
        Node * buildTree(int inorder[],int postorder[],int n){
            int postOrderIndex = n-1; // Root index
            map<int,int> nodeToIndex;
            createMapping(inorder,nodeToIndex,n);
            Node * res = solve(inorder,postorder,postOrderIndex,0,n-1,n,nodeToIndex);
            return res;
        }
};

int main()
{
    BinaryTree bt;
    int inorder[] = {4,8,2,5,1,6,3,7};
    int postorder[] = {8,4,5,2,6,7,3,1};
    int n = 8;
    bt.root = bt.buildTree(inorder,postorder,n);

    bt.levelOrderDisplay(bt.root);
    return 0;
}