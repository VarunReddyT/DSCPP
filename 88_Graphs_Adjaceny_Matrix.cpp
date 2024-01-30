#include<iostream>
using namespace std;

int arr[20][20];

void displayMatrix(int v){
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void add_edge(int v1, int v2){  // Add edge between 2 vertices
    arr[v1][v2] = 1;
    arr[v2][v1] = 1;
}   

int main()
{
    int vertices = 3;
    add_edge(0,1);
    add_edge(1,2);
    add_edge(2,2);
    displayMatrix(vertices);
    return 0 ;
}