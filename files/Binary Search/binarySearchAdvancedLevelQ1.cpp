#include<iostream>
#include<vector>
using namespace std;

bool canDistributeChocolate(vector<int>&arr, int mid , int s){
    int n = arr.size();
    int studentsreqd = 1;
    int currsum = 0;

    for(int i=0; i<n; i++){
        if(arr[i] > mid){
            return false;
        }

        if(currsum + arr[i] > mid){
            studentsreqd++;
            currsum = arr[i];
            if(studentsreqd > s) return false;
        }else{
            currsum += arr[i];
        }
    }
    return true;  
    
}

int distributeChocolate(vector<int>&arr, int s){
    int n = arr.size();
    int lo = arr[0];
    int hi = 0;

    for(int i=0; i<n; i++){
        hi += arr[i];
    }

    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(canDistributeChocolate(arr,mid,s)){
            ans = mid;
            hi = mid -1;
        }else{
            lo = mid +1;
        }
    }
    return ans;
    
}
int main(){
    vector<int>v;
    int n;
    cin>>n;

    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int s;
    cin>>s;

    cout<<distributeChocolate(v,s)<<endl;
    
    return 0;
}