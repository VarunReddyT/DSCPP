// * Using vector

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
template <typename T>

class AdjList{
    public:
        vector<list<T> > A;

        AdjList(int n){
            for (int i = 0; i < n; i++)
            {
                A.push_back({});
            }  
        }
        void add_edge(int v1, int v2){
            A[v1].push_back(v2);
            A[v2].push_back(v1);
        }

        void display(){
            for(int i = 0; i<A.size(); i++){
                cout << i << "->";
                for(auto j : A[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    AdjList<int> adj1(4);
    adj1.add_edge(0,1);
    adj1.add_edge(1,3);
    adj1.add_edge(2,3);
    adj1.display();
    
}