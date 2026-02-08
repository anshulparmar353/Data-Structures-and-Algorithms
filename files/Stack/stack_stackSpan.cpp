#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> stackSpan(vector<int>&arr){

    int n = arr.size();
    reverse(arr.begin(),arr.end());
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            output[st.top()] = n - i -1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        output[st.top()] = -1;
        st.pop();
    }

    reverse(output.begin(),output.end());
    return output;

}
int main(){

    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int>res = stackSpan(arr);
    for(int i=0; i<res.size(); i++){
        cout<<(i - res[i])<<" ";
    }cout<<endl;
    
    
    return 0;
}