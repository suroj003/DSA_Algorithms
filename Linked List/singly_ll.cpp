
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

    // Insert at the Beginning
    void push_front(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
            return;
        }

        newNode->next=head;
        head=newNode;
    }

    // Insert at the End
    void push_back(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
            return;
        }

        tail->next=newNode;
        tail=newNode;
    }

    // Delete Head
    void pop_front(){
        if(head==NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        Node* temp=head;
        head=head->next;
        delete temp;

        if(head==NULL){
            tail=NULL;
        }
    }

    // Delete Tail
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

        while(temp->next!=tail){
            temp=temp->next;
        }

        delete tail;
        tail=temp;
        tail->next=NULL;
    }

    // Insert at a Given Position (1-based)
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

        for(int i=1; i<pos-1 && temp!=NULL; i++){
            temp=temp->next;
        }

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
        temp->next=newNode;
    }

    // Delete at a Given Position (1-based)
    void delete_at_pos(int pos){
        if(head==NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        if(pos<1){
            cout<<"Invalid position\n";
            return;
        }

        if(pos==1){
            pop_front();
            return;
        }

        Node* temp=head;

        for(int i=1; i<pos-1 && temp!=NULL; i++){
            temp=temp->next;
        }

        if(temp==NULL || temp->next==NULL){
            cout<<"Invalid position\n";
            return;
        }

        Node* delNode=temp->next;
        temp->next=delNode->next;

        if(delNode==tail){
            tail=temp;
        }

        delete delNode;
    }

    // Display List
    void display(){
        if(head==NULL){
            cout<<"List is empty\n";
            return;
        }

        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }

        cout<<"NULL\n";
    }

    // Destructor to free remaining nodes
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
    int choice, val, pos;

    do{
        cout<<"\n===== LINKED LIST MENU =====\n";
        cout<<"1. Insert at Beginning\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Delete from Beginning\n";
        cout<<"4. Delete from End\n";
        cout<<"5. Insert at Position\n";
        cout<<"6. Delete at Position\n";
        cout<<"7. Display List\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
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
                cout<<"Exiting program...\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }

    }while(choice!=0);

    return 0;
}
