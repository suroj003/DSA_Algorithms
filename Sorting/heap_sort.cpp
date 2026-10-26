#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapSort(vector<int>&arr){
    int n=arr.size();
    priority_queue<int>pq;
    for(int val : arr){
        pq.push(val);
    }
    int idx=n-1;
    while(!pq.empty()){
        arr[idx--]=pq.top();
        pq.pop();
    }
}

int main(){
    vector<int>arr={64,25,12,22,11};
    cout<<"Original array: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    heapSort(arr);
    cout<<"\nSorted array: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}