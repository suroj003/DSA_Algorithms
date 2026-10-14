#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

class Queue{
    int arr[MAX];
    int front;
    int rear;
    int size;

    public:
    Queue(){
        front = -1;
        rear = -1;
        size = 0;
    }

    void push(int data){
        if(rear == MAX - 1){
            cout << "Queue is full" << endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = data;
        size++;
    }

    void pop(){
        if(front == -1){
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
        size--;
        if(front > rear){
            front = -1;
            rear = -1;
        }
    }

    int peek(){
        if(front == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        return size == 0;
    }

    int getSize(){
        return size;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front element is: " << q.peek() << endl;
    cout << "Queue size is: " << q.getSize() << endl;
    q.pop();
    cout << "Front element is: " << q.peek() << endl;
    cout << "Queue size is: " << q.getSize() << endl;
    return 0;
}