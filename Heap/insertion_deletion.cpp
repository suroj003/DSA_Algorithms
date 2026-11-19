#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    int * arr;
    int size;
    int total_size;

    public:
    MaxHeap(int total_size){
        arr=new int[total_size];
        this->total_size=total_size;
        size=0;
    }

    void insert(int val){
        if(size==total_size){
            cout<<"Heap Overflow"<<endl;
            return;
        }
        arr[size]=val;
        int index=size;
        size++;
        

        while(index>0 && arr[index]>arr[(index-1)/2]){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
        
        cout<<"Inserted "<<arr[index]<<" into the heap."<<endl;
        return;
    }

    void printHeap(){
        cout<<"The elements of the heap are: ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void Heapify(int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;    
        if(left<size && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<size && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=index){
            swap(arr[largest],arr[index]);
            Heapify(largest);
        }
    }
    void deleteMax(){
        if(size==0){
            cout<<"Heap Underflow"<<endl;
            return;
        }

        arr[0]=arr[size-1];
        size--;
        if(size==0){
            cout<<"Deleted the maximum element from the heap."<<endl;
            return;
        }

        Heapify(0);
    }
};

int main(){
    int total_size;
    cout<<"Enter the total size of the heap: ";
    cin>>total_size;

    MaxHeap heap(total_size);

    int n;
    cout<<"Enter the number of elements to insert into the heap: ";
    cin>>n;

    cout<<"Enter the elements to insert into the heap: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        heap.insert(val);
    }

    heap.printHeap();

    heap.deleteMax();
    heap.printHeap();

    return 0;
}