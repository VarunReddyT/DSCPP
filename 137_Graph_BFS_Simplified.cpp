#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Graph{
    public:
    vector<int> vertices;
    unordered_map<int, list<int> > adjList;

    void add_edge(int v1, int v2){
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
        }


    void BFS(int vertex, unordered_map<int,bool> & visited){
        queue <int> queue;

        if(!visited[vertex]){
            queue.push(vertex);
            visited[vertex] = true;
        }

        while(!queue.empty()){
            int front = queue.front();
            cout << front << " ";
            queue.pop();

            for(auto i : adjList[front]){
                if(!visited[i]){
                    queue.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.add_edge(0,3);
    g.add_edge(1, 3);
    g.add_edge(0, 2);
    g.add_edge(1, 4);

    unordered_map<int,bool> visited;

    for(int i = 0; i<5; i++){
        visited[i] = false;   // Make all the vertices false at first 
    }

    cout << "BFS : " << endl;
    g.BFS(0,visited);

    return 0 ;
}