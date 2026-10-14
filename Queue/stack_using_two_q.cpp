#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    int size;

    public:
    Stack(){
        size = 0;
    }

    void push(int data){
        q1.push(data);
        size++;
    }

    void pop(){
        if(q1.empty()){
            cout << "Stack is empty" << endl;
            return;
        }
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        size--;
        swap(q1, q2);
    }

    int top(){
        if(q1.empty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int data = q1.front();
        q2.push(data);
        q1.pop();
        swap(q1, q2);
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
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    cout << "Stack size: " << s.getSize() << endl;
    return 0;
}