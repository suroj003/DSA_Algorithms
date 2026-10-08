#include<bits/stdc++.h>
using namespace std;

void prefixToPostfix(string s){
    stack<string>st;
    for(int i=s.length()-1;i>=0;i--){
        if((s[i]>'a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            st.push(to_string(s[i]));
        }
        else{
            //Operator
            char op=s[i];
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string newTop=op+top1+top2;
            st.push(newTop);
        }
    }
    cout<<"Postfix Expression : "<<st.top()<<endl;
}

int main(){
    string s;
    cout<<"Enter a Prefix Expression : ";
    cin>>s;
    prefixToPostfix(s);
    return 0;
}