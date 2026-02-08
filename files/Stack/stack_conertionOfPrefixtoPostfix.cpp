#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

string eval(string &pre){

    reverse(pre.begin(),pre.end());

    stack<string>st;
    for(int i=0; i<pre.size(); i++){
        if(isdigit(pre[i])){
            st.push(to_string(pre[i] - '0'));
        }else{
            string v1 = st.top();
            st.pop();
            string v2 =st.top();
            st.pop();
            string nextexp = v1 + v2 + pre[i];
            st.push(nextexp);
        }
    }
    return st.top();
}

int main(){

    string pre;
    cin>>pre;

    string post = eval(pre);

    for(int i=0; i<post.size(); i++){
        cout<<post[i];
    }cout<<endl;
    
    return 0;
}