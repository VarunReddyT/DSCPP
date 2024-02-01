#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int> > adjList;
        vector<int> vertices;

        void add_edge(int v1, int v2, bool directed){
            
            if(v2 != -1){
                adjList[v1].push_back(v2);
                if(directed == 0){
                    adjList[v2].push_back(v1);
                }

                if(vertex_checker(v1)){
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
            if(ver != vertices.end()){
                return false;
            }
            return true;
        }

        void DFS(int vertex, unordered_map<int,bool> & visited){

            stack<int> stack;

            if(!visited[vertex]){
                stack.push(vertex);
                visited[vertex] = true;
            }

            while(!stack.empty()){
                int top = stack.top();
                cout << top << " ";
                stack.pop();

                for(auto i : adjList[top]){
                    if(!visited[i]){
                        stack.push(i);
                        visited[i]= true;
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

    cout << "DFS : " << endl;

    for(int i = 0; i<g.vertices.size(); i++){
        g.DFS(g.vertices[i],visited);
    }
    return 0 ;
}