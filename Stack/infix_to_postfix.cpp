#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/' || c=='%'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

void display(stack<char>st){
    cout << "Stack: ";

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

void infixToPostfix(string s){
    stack<char>st;
    string res;

    for(int i=0;i<s.length();i++){

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }

        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();
        }

        else{
            while(!st.empty() && priority(st.top())>=priority(s[i])){
                res+=st.top();
                st.pop();
            }

            st.push(s[i]);
        }

        display(st);
    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    cout << "Postfix: " << res << endl;
}

int main(){
    string s;
    cout<<"Enter a infix expression: ";
    cin>>s;
    infixToPostfix(s);
}