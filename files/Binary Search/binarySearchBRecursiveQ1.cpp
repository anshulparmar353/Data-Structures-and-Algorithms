#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>&input, int target, int lo, int hi ){

    int ans=-1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(input[mid] == target ){
            ans=mid;
            return ans;
        }else if (input[mid] < target){
            return binarySearch(input,target,mid+1,hi);
        }else{
            return binarySearch(input,target,lo,mid-1);
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

    cout<<binarySearch(input,target,0,n-1);

    return 0;
}