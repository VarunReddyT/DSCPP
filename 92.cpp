#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;
class graph{
    public:
    vector <int> vertices;
    unordered_map< int , list<int>> adjList;

    void addedge(int u , int v , bool direction ){
        // v=-1 that means u is a isolated node in (un)directed graph or a node in connected directed graph which is not directed to any other node
        if(v != -1){
            adjList[u].push_back(v);

            if(direction == 0){
            adjList[v].push_back(u);
            }
            if(!v_checker(u)){
            vertices.push_back(u);
            }
            if(!v_checker(v)){
            vertices.push_back(v);
            }
        }
        else{
            adjList[u];
            if(!v_checker(u)){
            vertices.push_back(u);
        }
        }
        
        
    }

    bool v_checker(int v){   // Checks if a vertex v is already present in vertices vector.
        auto it = find(vertices.begin(), vertices.end(),v);
        if(it !=vertices.end()){
            return true;
        }
        return false;
    }

    void print_adjL(){
        for(auto i : adjList){
            cout<< i.first << " -> ";
            for(auto j : i.second){
                cout<< j << " ";
            }
            cout << endl;
        }
    }

    void BFS(int vertex , unordered_map <int , bool> & visited){

        queue<int> check_list; // checklist to check whether the algo has visited the node or not
        
        if(!visited[vertex]){
        check_list.push(vertex);
        visited[vertex] = true;
        }

       while(!check_list.empty()){
        int front_node = check_list.front();
        cout<< front_node << " ";
        check_list.pop();
        for(auto i : adjList[front_node]){
            if(!visited[i]){
                check_list.push(i);
                visited[i] = true;
            }
        }
       }
    }

    
};

int main() {

    graph g;

    g.addedge(0,3,0);
    g.addedge(1,3,0);
    g.addedge(1,2,0);
    g.addedge(1,4,0);
    g.addedge(5,-1,0); // isolated vertex

    unordered_map<int , bool > vist;
    for( int i=0; i < g.vertices.size();i++){
        vist[g.vertices[i]] = false;
    }

    for(int i = 0 ; i < g.vertices.size();i++){ // this loop is used in case if graph is disconnected.
        g.BFS(g.vertices[i],vist);
    }
   g.print_adjL();

    return 0;
}