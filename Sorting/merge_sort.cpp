#include<bits/stdc++.h>
using namespace std;

//*MERGING TWO PORTIONS OF ARRAY
void merge(vector<int>&arr,int start,int mid,int end){
    vector<int>temp(end-start+1);
    int left=start;
    int right=mid+1;
    int index=0;

    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index]=arr[left];
            index++;
            left++;
        }
        else{
            temp[index]=arr[right];
            index++;
            right++;
        }
    }

    //!LEFT IN LEFT PORTION
    while(left<=mid){
        temp[index]=arr[left];
        index++;
        left++;
    }

    //!LEFT IN RIGHT PORTION
    while(right<=end){
        temp[index]=arr[right];
        index++;
        right++;
    }

    //!TRANSFERING VECTOR TO ORIGINAL ARRAY
    index=0;
    while(start<=end){
        arr[start]=temp[index];
        index++;
        start++;
    }
}

//*MERGE SORT FUNCTION
void mergeSort(vector<int>&arr,int start,int end){
    if(start==end){
        return;
    }
    int mid=start+(end-start)/2;

    //?LEFT
    mergeSort(arr,start,mid);
    //?RIGHT
    mergeSort(arr,mid+1,end);

    //*MERGE THE PORTIONS
    merge(arr,start,mid,end);

}


int main(){
    
    vector<int>arr={64,25,12,22,11};
    cout<<"Original array: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    mergeSort(arr,0,arr.size()-1);
    cout<<"\nSorted array: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
