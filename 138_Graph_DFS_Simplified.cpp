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

        void add_edge(int v1, int v2){
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
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
    g.add_edge(0,3);
    g.add_edge(1, 3);
    g.add_edge(0, 2);
    g.add_edge(1, 4);

    unordered_map<int,bool> visited;

    for(int i = 0; i<4; i++){
        visited[i] = false;   // Make all the vertices false at first 
    }

    cout << "DFS : " << endl;

    g.DFS(0,visited);
    return 0 ;
}