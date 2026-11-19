#include<bits/stdc++.h>
using namespace std;


void Heapify(int arr[],int n,int idx){
    int largest=idx;
    int left=2*idx+1;
    int right=2*idx+2;

    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=idx){
        swap(arr[largest],arr[idx]);
        Heapify(arr,n,largest);
    }
}
void buildHeap(int arr[],int n){
    //Step Down Approach;
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,n,i);
    }
}

void printHeap(int arr[],int n){
    cout<<"The elements of the heap are: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    buildHeap(arr,n);

    printHeap(arr,n);
    return 0;
}