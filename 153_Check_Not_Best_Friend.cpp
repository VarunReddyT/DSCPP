// PS 2-2 C++ Test
// An element is known as a 'best friend' of the other, if they are directly connected to each other.
// If they are indirectly connected, then they are 'not best friends'
// Program to print all the not best friends of the element '11'

// 11-----13
//  |\    |
//  | \   |
//  |  \  |
//  |   \ |
// 12    64
//  |   / |
//  |  /  |
//  | /   |
//  79    96

// For element 11, 79 and 96 are not best friends as they are not directly connected.

// Input:
// Enter the number of nodes and edges : 6 7
// Enter the nodes : 
// 11 12 13 79 64 96
// Enter the two vertices v1 and v2 : 
// 11 12
// 11 13 
// 11 64
// 12 79
// 64 79
// 64 96
// 13 64
// Enter the element to check : 
// 11

// Output:
// 79 96

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int v1, int v2){
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }

        void checkNotBF(int arr[],int v, int n){
            for(auto i : adjList[v]){
                for(int j = 0; j<n; j++){
                    if(arr[j] == i){
                        arr[j] = 0;
                    }
                    if(arr[j] == v){
                        arr[j] = 0;
                    }
                }
            }
            
            for(int i = 0; i<n; i++){
                if(arr[i] != 0){
                    cout << arr[i] << " ";
                }
            }
        }
};

int main()
{
    int edges;
    int nodes;
    cout << "Enter the number of nodes and edges : ";
    cin >> nodes >> edges;
    cout << "Enter the nodes : "<<endl;
    int arr[nodes];
    for(int i = 0;i<nodes; i++){
        int elem;
        cin >> elem;
        arr[i] = elem;
    }
    Graph g;

    int v1,v2;

    cout << "Enter the two vertices v1 and v2 : " << endl;
    for(int i = 0; i<edges; i++){
        cin >> v1 >> v2;
        g.addEdge(v1,v2);
    }

    int elementToCheck;
    cout << "Enter the element to check : " << endl;
    cin >> elementToCheck;

    g.checkNotBF(arr,elementToCheck,nodes);
    return 0 ;
}