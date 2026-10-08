#include<bits/stdc++.h>
using namespace std;

void prefixToInfix(string s){
    stack<string>st;

    for(int i=s.length()-1;i>=0;i--){
        if((s[i]>='a' && s[i]<='z') || 
           (s[i]>='A' && s[i]<='Z') || 
           (s[i]>='0' && s[i]<='9')){
            
            st.push(string(1,s[i]));
        }
        else{
            // Operator
            char op=s[i];

            string top1=st.top();
            st.pop();

            string top2=st.top();
            st.pop();

            string newTop="("+top2+op+top1+")";

            st.push(newTop);
        }
    }

    cout<<"Infix Expression : "<<st.top()<<endl;
}

int main(){
    string s;
    cout<<"Enter a Prefix Expression : ";
    cin>>s;

    prefixToInfix(s);

    return 0;
}