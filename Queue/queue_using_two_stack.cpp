#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    int size;

    public:
    Queue(){
        size = 0;
    }

    void push(int data){
        s1.push(data);
        size++;
    }

    void pop(){
        if(s1.empty()){
            cout << "Queue is empty" << endl;
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        size--;
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int peek(){
        if(s1.empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int data = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return data;
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