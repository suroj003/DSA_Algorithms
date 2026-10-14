#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;
    int size;

    public:
    Queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(front == NULL){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    int peek(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
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
    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.getSize() << endl;
    q.pop();
    cout << "Front element after pop: " << q.peek() << endl;
    cout << "Queue size after pop: " << q.getSize() << endl;
    return 0;
}