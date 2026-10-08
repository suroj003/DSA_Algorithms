#include <bits/stdc++.h>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int size;

public:
    Stack(int n) {
        size = n;
        top = -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = x;
        cout << x << " pushed\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top] << " popped\n";
        top--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top: " << arr[top] << endl;
    }
};

int main() {
    int n, choice, x;

    cout << "Enter stack size: ";
    cin >> n;

    Stack st(n);

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
                st.push(x);
                break;

            case 2:
                st.pop();
                break;

            case 3:
                st.peek();
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