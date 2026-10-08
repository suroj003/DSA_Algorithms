void display(stack<char> st){
    cout << "Stack: ";

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}
