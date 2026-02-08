#include<iostream>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

int largestAreaRectangle(vector<int> &arr){

    int n = arr.size();
    stack<int>st;
    st.push(0);
    int ans = INT_MIN;

    for(int i=1; i<n; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            int element = arr[st.top()];
            st.pop();
            int nsi = i;
            int psi = (st.empty()) ? (-1) : st.top();
            ans = max( ans , element*(nsi - psi - 1) );
        }
        st.push(i);
    }
    while(!st.empty()){
        int element = arr[st.top()];
        st.pop();
        int nsi = n;
        int psi = (st.empty()) ? (-1) : st.top();
        ans = max( ans , element*(nsi - psi - 1) );
        
    }

    return ans;

}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = largestAreaRectangle(arr);
    cout<<ans<<endl;

    
    return 0;
}