// * Using unordered_map

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
template <typename T>

class AdjList{
    public:
        unordered_map<T, list<T>> adjList;

        void addEdge(T u, T v, bool directed){

            // directed == 0 -> undirected graph and directed == 1 -> directed graph;
            adjList[u].push_back(v);

            if(directed == 0){
                adjList[v].push_back(u);
            }
        }

        void display(){
            cout << "Linked Vertices" << endl;
            for(auto i : adjList){
                cout << i.first << "->";
                for(auto j : i.second){
                    cout << j << " ";
                }
                cout << endl;
            } 
        }
};

int main()
{
    int edges;
    cout << "Enter the number of edges : ";
    cin >> edges;

    AdjList<int> adj;

    int v1,v2;

    for(int i = 0; i<edges; i++){
        cout << "Enter the two vertices v1 and v2 : " << endl;
        cin >> v1 >> v2;
        adj.addEdge(v1,v2,0);   // 1 for directed graph
    }

    adj.display();
    return 0 ;
}