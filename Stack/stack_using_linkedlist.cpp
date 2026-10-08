#include <bits/stdc++.h>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    Stack() {
        head = NULL;
    }

    Node* createNode(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;
        return newNode;
    }

    bool isEmpty() {
        return head == NULL;
    }

    bool isFull() {
        Node* temp = new(nothrow) Node;

        if (temp == NULL)
            return true;

        delete temp;
        return false;
    }

    void push_front(int x) {
        Node* newNode = createNode(x);

        newNode->next = head;
        head = newNode;

        cout << x << " pushed\n";
    }

    void pop_front() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = head;

        cout << temp->data << " popped\n";

        head = head->next;
        delete temp;
    }

    void top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top: " << head->data << endl;
    }
};

int main() {
    int choice, x;

    Stack st;

    while (true) {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Is Full\n";
        cout << "5. Is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                st.push_front(x);
                break;

            case 2:
                st.pop_front();
                break;

            case 3:
                st.top();
                break;

            case 4:
                cout << (st.isFull() ? "Stack is Full\n" : "Stack is not Full\n");
                break;

            case 5:
                cout << (st.isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n");
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}