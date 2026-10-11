
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data=val;
        prev=next=NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
            return;
        }

        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }

    void push_back(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
            return;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    void pop_front(){
        if(head==NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        Node* temp=head;
        head=head->next;

        if(head==NULL)
            tail=NULL;
        else
            head->prev=NULL;

        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        Node* temp=tail;
        tail=tail->prev;

        if(tail==NULL)
            head=NULL;
        else
            tail->next=NULL;

        delete temp;
    }

    void insert_at_pos(int val, int pos){
        if(pos<1){
            cout<<"Invalid position\n";
            return;
        }

        if(pos==1){
            push_front(val);
            return;
        }

        Node* temp=head;

        for(int i=1; i<pos-1 && temp!=NULL; i++)
            temp=temp->next;

        if(temp==NULL){
            cout<<"Invalid position\n";
            return;
        }

        if(temp==tail){
            push_back(val);
            return;
        }

        Node* newNode=new Node(val);
        newNode->next=temp->next;
        newNode->prev=temp;

        temp->next->prev=newNode;
        temp->next=newNode;
    }

    void delete_at_pos(int pos){
        if(head==NULL || pos<1){
            cout<<"Invalid position or empty list\n";
            return;
        }

        if(pos==1){
            pop_front();
            return;
        }

        Node* temp=head;

        for(int i=1; i<pos && temp!=NULL; i++)
            temp=temp->next;

        if(temp==NULL){
            cout<<"Invalid position\n";
            return;
        }

        if(temp==tail){
            pop_back();
            return;
        }

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        delete temp;
    }

    void display(){
        if(head==NULL){
            cout<<"List is empty\n";
            return;
        }

        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"<-->";
            temp=temp->next;
        }

        cout<<"NULL\n";
    }

    ~List(){
        while(head!=NULL){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        tail=NULL;
    }
};

int main(){
    List l;
    int choice,val,pos;

    do{
        cout<<"\n--- DOUBLY LINKED LIST ---\n";
        cout<<"1. Push Front\n2. Push Back\n";
        cout<<"3. Pop Front\n4. Pop Back\n";
        cout<<"5. Insert at Position\n6. Delete at Position\n";
        cout<<"7. Display\n0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>val;
                l.push_front(val);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>val;
                l.push_back(val);
                break;
            case 3:
                l.pop_front();
                break;
            case 4:
                l.pop_back();
                break;
            case 5:
                cout<<"Enter value and position: ";
                cin>>val>>pos;
                l.insert_at_pos(val,pos);
                break;
            case 6:
                cout<<"Enter position: ";
                cin>>pos;
                l.delete_at_pos(pos);
                break;
            case 7:
                l.display();
                break;
            case 0:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice\n";
        }
    }while(choice!=0);

    return 0;
}
