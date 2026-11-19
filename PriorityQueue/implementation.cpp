#include<iostream>
#include<vector>
#include<algorithm> 
#include<list>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    int priority;

    Node(int val, int prio){
        data=val;
        priority=prio;
        next=NULL;
    }
};

class PQ{
    Node* head;
    public:
    PQ(){
        head=NULL;
    }

    void push(int val,int priority){
        Node* newNode=new Node(val,priority);

        if(head==NULL || head->priority>priority){
            newNode->next=head;
            head=newNode;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL && temp->next->priority<=priority){
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    void pop(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int front(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }
};

int main(){
    PQ pq;
    pq.push(10,2);
    pq.push(20,1);
    pq.push(30,3);
    pq.pop();
    pq.display();
    cout<<"Front element: "<<pq.front()<<endl;
    return 0;
}