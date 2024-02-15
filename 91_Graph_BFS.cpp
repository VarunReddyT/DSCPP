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

    void add_edge(int v1, int v2, bool directed){
        if(v2 != -1){
            adjList[v1].push_back(v2);
            if(directed == 0){
                adjList[v2].push_back(v1);
            }

            if(vertex_checker(v1)){  // True if vertex not found
                vertices.push_back(v1);
            }
            if(vertex_checker(v2)){
                vertices.push_back(v2);
            }
        }
        else{
            adjList[v1];
            if(vertex_checker(v1)){
                vertices.push_back(v1);
            }
        }
    }

    bool vertex_checker(int v){
        auto ver = find(vertices.begin(),vertices.end(),v);

        if(ver != vertices.end()){  // That means vertex is found
            return false;
        }
        return true;
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
    g.add_edge(0,3,0);
    g.add_edge(1, 3, 0);
    g.add_edge(1, 2, 0);
    g.add_edge(1, 4, 0);
    g.add_edge(5, -1, 0);

    unordered_map<int,bool> visited;

    for(int i = 0; i<g.vertices.size(); i++){
        visited[g.vertices[i]] = false;   // Make all the vertices false at first 
    }

    cout << "BFS : " << endl;

    for(int i = 0; i<g.vertices.size(); i++){
        g.BFS(g.vertices[i],visited);
    }

    return 0 ;
}