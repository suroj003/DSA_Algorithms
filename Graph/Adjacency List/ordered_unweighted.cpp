#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertex,edge;
    cout<<"Enter the number of vertex and edge: ";
    cin>>vertex>>edge;

    vector<int>AdjList[vertex];
    int u,v;
    cout<<"Enter the edges: ";
    for(int i=0;i<edge;i++){
        cin>>u>>v;
        AdjList[u].push_back(v);
    }

    for(int i=0;i<vertex;i++){
        cout<<i<<"->";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
    }
}