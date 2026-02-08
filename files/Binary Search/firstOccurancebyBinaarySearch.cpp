#include<iostream>
#include<vector>
using namespace std;

int firstOccurance(vector<int>&input, int target){

    int lo = 0;
    int hi=input.size()-1;
    int ans=-1;

    while(lo<=hi){

        int mid = lo + (hi-lo)/2;   // or ( lo + hi)/2
        if(input[mid] == target){
            ans=mid;
            hi=mid-1;
        }else if(input[mid] < target){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return ans;
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

    cout<<firstOccurance(input,target);

    return 0;
}