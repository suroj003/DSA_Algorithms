#include<iostream>
#include<algorithm>
using namespace std;


int partition(int arr[],int st,int end){
    int pos=st;
    for(int i=st;i<=end;i++){
        if(arr[i]<=arr[end]){
            swap(arr[i],arr[pos]);
            pos++;
        }
    }
    return pos-1;
}
void quickSort(int arr[],int st,int end){
    if(st>=end){
        return;
    }

    int pivot=partition(arr,st,end);

    //*Left
    quickSort(arr,st,pivot-1);
    //*Right
    quickSort(arr,pivot+1,end);
}

int main(){
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}