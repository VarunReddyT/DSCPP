#include<iostream>
using namespace std;
#define N 1000
class BinaryTree{
    int arr[N];
    int top = 0;
    int root;
    public: 
        BinaryTree(int root){
            arr[0] = root;
            top++;
        }

        void setLeft(int rootIndex, int val){
            arr[(rootIndex*2) + 1] = val;
            top++;
        }

        void setRight(int rootIndex, int val){
            arr[(rootIndex*2) + 2] = val;
            top++;
        }

        int size(){
            return top;
        }

        int parentIndex(int index){
            return ((index-1)/2);
        }

        void printTree(int n){
            for(int i = 0;i<n; i++){
                if(arr[i] == ' '){
                    cout << "_" << " ";
                }
                else{
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
        }

        void InOrderDisplay(int root){
            if(root >= top){
                return;
            }
            InOrderDisplay(2*root + 1);
            cout << arr[root] << " ";
            InOrderDisplay(2*root + 2);
        }
        void PreOrderDisplay(int root){
            if(root >= top){
                return;
            }
            cout << arr[root] << " ";
            PreOrderDisplay(2*root + 1);
            PreOrderDisplay(2*root + 2);
        }
        void PostOrderDisplay(int root){
            if(root >= top){
                return;
            }
            PostOrderDisplay(2*root + 1);
            PostOrderDisplay(2*root + 2);
            cout << arr[root] << " ";
        }
};

int main()
{
    BinaryTree bt(2);
    bt.setLeft(0,5);
    bt.setRight(0,3);
    bt.setLeft(1,1);
    bt.setRight(1,6);
    bt.setLeft(2,15);
    bt.setRight(2,10);

    cout << "Binary Tree Array" << endl;
    bt.printTree(7);

    cout << "PreOrderDisplay: ";
    bt.PreOrderDisplay(0);
    cout << endl;

    cout << "PostOrderDisplay: ";
    bt.PostOrderDisplay(0);
    cout << endl;

    cout << "InOrderDisplay: ";
    bt.InOrderDisplay(0);
    cout << endl;

    cout << "Size of the Array : " << bt.size() << endl;
    return 0 ;
}