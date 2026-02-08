#include<iostream>
#include<stack>
using namespace std;

bool isBracketBalanced(string &str){

    stack<char> st;
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch =='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }else{
            if(ch==')' && !st.empty() && st.top()=='('){
                st.pop();
            }else if(ch==']' && !st.empty() && st.top()=='['){
                st.pop();
            }else if(ch=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }else{
                return false;
            }

        }

    }
    return st.empty(); // true if stack is empty
}

int main(){
    string str = "[[]]{}{(}";
    cout<<"THE GIVEN BRACKET STIRNG IS: "<<endl;
    cout<<isBracketBalanced(str)<<endl;
    
    return 0;
}