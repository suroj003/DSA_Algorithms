#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/' || c=='%') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

void display(stack<char> st){
    cout << "Stack: ";

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

//Concept is to reverse the infix expression given and then apply the infix to postfix conversion algorithm and then reverse the result to get the prefix expression. Treat ( as ) and vice versa while reversing the infix expression.
void infixToPrefix(string s){
    reverse(s.begin(),s.end());
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && priority(st.top())>=priority(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
            display(st);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}


int main(){
    string s;
    cout<<"Enter the infix expression: ";
    cin>>s;
    infixToPrefix(s);
    return 0;
}