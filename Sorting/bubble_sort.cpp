#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int>arr={64,25,12,22,11};
    cout<<"Original array: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    bubbleSort(arr);
    cout<<"\nSorted array: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}