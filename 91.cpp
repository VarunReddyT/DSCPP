// #include<iostream>
// #include<list>
// #include<queue>
// #include<algorithm>
// #include<unordered_map>
// using namespace std;

// class Graph{
//     public:
//     vector<int> vertices;
//     unordered_map<int, list<int> > adjList;

//     void add_edge(int v1, int v2, bool directed){
//         if(v2 != 1){
//             adjList[v1].push_back(v2);
//             if(directed == 0){
//                 adjList[v2].push_back(v1);
//             }

//             if(vertex_checker(v1)){  // True if vertex not found
//                 vertices.push_back(v1);
//             }
//             if(vertex_checker(v2)){
//                 vertices.push_back(v2);
//             }
//         }
//         else{
//             adjList[v1];
//             if(vertex_checker(v1)){
//                 vertices.push_back(v1);
//             }
//         }
//     }

//     bool vertex_checker(int v){
//         auto ver = find(vertices.begin(),vertices.end(),v);

//         if(ver == vertices.end()){  // That means vertex is not found
//             return true;
//         }
//         return false;
//     }

//     void display(){
//         for(auto i : adjList){
//             cout << i.first << " -> ";
//             for(auto j : i.second){
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//     }

//     void BFS(int vertex, unordered_map<int,bool> & visited){
        
//     }
// };
// int main()
// {
    
//     return 0 ;
// }