#include<bits/stdc++.h>
using namespace std;

void postfixToPrefix(string s){
    stack<string>st;
    for(int i=0;i<s.length();i++){
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
    cout<<"Prefix Expression : "<<st.top()<<endl;
}

int main(){
    string s;
    cout<<"Enter a Postfix Expression : ";
    cin>>s;
    postfixToPrefix(s);
    return 0;
}