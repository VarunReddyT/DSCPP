#include<iostream>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }
        
        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;
            while(index > 1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else{
                    break;
                }
            }
        }

        // 1st element is set as -1, we start the elements from index 1    
    
        void display(){
            for(int i = 1; i<=size;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    heap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(1);
    maxHeap.insert(324);
    maxHeap.insert(34);
    maxHeap.insert(76);
    maxHeap.insert(2);
    maxHeap.insert(100);
    maxHeap.insert(50);

    maxHeap.display();
    return 0;
}