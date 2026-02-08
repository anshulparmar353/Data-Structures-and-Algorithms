#include<iostream>
#include<vector>
using namespace std;

int findtarget(vector<int> &input, int target){
    
    int lo=0; 
    int hi=input.size()-1;

    while (lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(input[mid] == target) return mid;
        if(input[mid] >= input[lo]){
            if(target >= input[lo] && target <= input[mid]){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }else{
            if(target >= input[mid] && target <= input[hi]){
                lo = mid +1;
            }else{
                hi = mid -1;
            }
        }
    }
    return -1;
}
int main(){

    vector<int>input;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    int target;
    cin>>target;
    
    cout<<findtarget(input,target);

    return 0;
}