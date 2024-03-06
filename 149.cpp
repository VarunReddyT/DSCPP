#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int> > adjList;

    void add_edge(int v1, int v2){
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
        }

    vector<int> shortestPath(unordered_map<int,bool> &visited,int sourceNode, int destinationNode){
        unordered_map<int,int> parent;
        // BFS
        queue<int> q;
        q.push(sourceNode);
        visited[sourceNode] = true;
        parent[sourceNode] = -1;  // First element's parent is set to -1
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto i : adjList[front]){
                if(!visited[i]){
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }

        vector<int> ans;
        int currentNode = destinationNode;
        ans.push_back(destinationNode);
        while(currentNode != sourceNode){
            currentNode = parent[currentNode];
            ans.push_back(currentNode);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void display(){
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
    Graph g;
    g.add_edge(1,2);
    g.add_edge(2,5);
    g.add_edge(5,8);
    g.add_edge(1,3);
    g.add_edge(3,8);
    g.add_edge(1,4);
    g.add_edge(4,6);
    g.add_edge(6,7);
    g.add_edge(7,8);

    unordered_map<int,bool> visited;

    for(int i = 0; i<5; i++){
        visited[i] = false;   // Make all the vertices false at first 
    }

    g.display();
    
    vector<int> res;
    res = g.shortestPath(visited,1,8);

    cout << "Shortest Path is : ";
    for(int i = 0; i<res.size() ; i++){
        cout << res[i] << " ";
    }

    return 0 ;
}