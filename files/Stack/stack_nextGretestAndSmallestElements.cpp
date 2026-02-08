#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGretestEle(vector<int>&arr){

    int n = arr.size();

    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);

    for(int i=1; i<n; i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        output[st.top()] = -1;
        st.pop();
    }

    return output;
}

// vector<int> nextSmallestEle(vector<int>&arr){
//     // 1.reverse the array 
//     //2. find next geatest element
//     //3. reverse the resultant array 
//     //4. you will get next greatest element
// }

//OR

vector<int> nextSmallestEle(vector<int>&arr){

    int n = arr.size();

    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);

    for(int i=1; i<n; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        output[st.top()] = -1;
        st.pop();
    }

    return output;
}



int main(){

    vector<int> arr;
    cout<<"enter the size of array:"<<endl;
    int n;
    cin>>n;  

    cout<<"enter the elements of array: "<<endl;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    vector<int>res = nextSmallestEle(arr);

    cout<<"THE NEXT SMALLEST ELEMENTS ARRAY IS:"<<endl;
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }cout<<endl;  

    return 0;
}