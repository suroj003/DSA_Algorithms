
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
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
            tail->next=head;
            return;
        }

        newNode->next=head;
        head=newNode;
        tail->next=head;
    }

    void push_back(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
            return;
        }

        tail->next=newNode;
        tail=newNode;
        tail->next=head;
    }

    void pop_front(){
        if(head==NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        Node* temp=head;

        if(head==tail){
            head=tail=NULL;
        }
        else{
            head=head->next;
            tail->next=head;
        }

        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }

        Node* temp=head;

        while(temp->next!=tail)
            temp=temp->next;

        delete tail;
        tail=temp;
        tail->next=head;
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

        for(int i=1; i<pos-1 && temp!=tail; i++)
            temp=temp->next;

        if(temp==tail){
            if(pos==1)
                push_front(val);
            else if(pos==2 && head==tail)
                push_back(val);
            else if(pos>1){
                if(pos==2 && head!=tail){
                    Node* newNode=new Node(val);
                    newNode->next=head;
                    head=newNode;
                    tail->next=head;
                }
                else{
                    // Validate the requested position.
                    Node* check=head;
                    int count=1;
                    while(check!=tail){
                        check=check->next;
                        count++;
                    }

                    if(pos==count+1)
                        push_back(val);
                    else
                        cout<<"Invalid position\n";
                }
            }
            return;
        }

        Node* newNode=new Node(val);
        newNode->next=temp->next;
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

        for(int i=1; i<pos-1 && temp->next!=head; i++)
            temp=temp->next;

        if(temp->next==head){
            cout<<"Invalid position\n";
            return;
        }

        Node* delNode=temp->next;
        temp->next=delNode->next;

        if(delNode==tail)
            tail=temp;

        delete delNode;
        tail->next=head;
    }

    void display(){
        if(head==NULL){
            cout<<"List is empty\n";
            return;
        }

        Node* temp=head;

        do{
            cout<<temp->data<<"-->";
            temp=temp->next;
        }while(temp!=head);

        cout<<"(HEAD)\n";
    }

    ~List(){
        if(head==NULL)
            return;

        tail->next=NULL;

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
        cout<<"\n--- CIRCULAR LINKED LIST ---\n";
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
