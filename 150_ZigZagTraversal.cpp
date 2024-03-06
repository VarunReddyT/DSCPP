#include<iostream>
#include<vector>
#include<queue>
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

        vector<int> ZigZagTraversal(Node * root){
            vector<int> res;
            if(root == NULL){
                return res;
            }
            queue<Node *> q;
            q.push(root);
            bool leftToRight = true;
            while(!q.empty()){
                int size = q.size();
                vector<int> ans(size);
                for(int i = 0; i<size; i++){
                    Node * frontNode = q.front();
                    q.pop();

                    int index = leftToRight ? i : size-i-1;
                    ans[index] = frontNode->val;
                    
                    if(frontNode->left){
                        q.push(frontNode->left);
                    }
                    if(frontNode->right){
                        q.push(frontNode->right);
                    }

                }
            leftToRight = !leftToRight;
            for(auto i : ans){
                res.push_back(i);
            }
            }
            return res;
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
};

int main()
{
    BinaryTree bt;
    Node * root = NULL;
    cout << "Enter root : ";
    bt.root = bt.create(root);

    cout << "Binary Tree is : " << endl;
    bt.levelOrderDisplay(bt.root);

    vector<int> res = bt.ZigZagTraversal(bt.root);
    cout << "Zig Zag Traversal of the binary tree is : " << endl;
    for(int i = 0; i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}