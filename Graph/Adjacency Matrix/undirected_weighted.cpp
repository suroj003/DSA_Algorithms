#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertex,edge;
    cout<<"Enter the number of vertex and edge: ";
    cin>>vertex>>edge;

    vector<vector<bool>>AdjMat(vertex,vector<bool>(vertex,0));

    int u,v,weight;
    cout<<"Enter the edges and weights: ";
    for(int i=0;i<edge;i++){
        cin>>u>>v>>weight;
        AdjMat[u][v]=weight;
        AdjMat[v][u]=weight;
    }

    //Print the adjacency matrix
    cout<<"The adjacency matrix is : "<<endl;
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}