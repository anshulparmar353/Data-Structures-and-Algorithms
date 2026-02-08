#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxNumInWindow(vector<int> &arr, int k){
    deque<int> dq;
    vector<int> res;

    // Process the first 'k' elements
    for(int i=0; i<k; i++){
        while(!dq.empty() && arr[dq.back()] < arr[i]){
            dq.pop_back();  // Remove all elements smaller than current element
        }
        dq.push_back(i);  // Add current element index to the deque
    }
    res.push_back(arr[dq.front()]);  // The maximum of the first window

    // Process the rest of the elements from index 'k' to 'n-1'
    for(int i=k; i<arr.size(); i++){
        int curr = arr[i];

        // Remove the elements that are out of this window
        if(dq.front() == (i-k)){
            dq.pop_front();
        }

        // Remove all elements smaller than current element from the back of the deque
        while(!dq.empty() && arr[dq.back()] < curr){
            dq.pop_back();
        }

        dq.push_back(i);  // Add current element index to the deque
        res.push_back(arr[dq.front()]);  // The maximum of the current window
    }
    return res;
}
                    
int main(){
    int n;
    cin>>n;  // Number of elements in the array
    vector<int> arr(n);

    // Input array elements
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;  // Size of the sliding window

    // Get the result (max of each sliding window)
    vector<int> result = maxNumInWindow(arr,k);

    // Output the result
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
