#include<iostream>
using namespace std;

int LinearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Element found at index: "<<i<<endl;
            return i;
        }
    }
    cout<<"Element not found"<<endl;
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element to be searched: ";
    cin>>target;
    LinearSearch(arr,n,target);
    return 0; 
}