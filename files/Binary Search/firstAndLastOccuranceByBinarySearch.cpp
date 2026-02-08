#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int>&input, int target){

    int lo=0; 
    int hi=input.size()-1;
    int ans=-1;

    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(input[mid] >= target){
            ans=mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>&input, int target){

    int lo=0; 
    int hi=input.size()-1;
    int ans=-1;

    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(input[mid] > target){
            ans=mid;
            hi = mid - 1 ;
        }else{
            lo = mid + 1;
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
    vector<int>result;
    int lb = lowerBound(input,target);
    if(input[lb] != target){
        result.push_back(-1);
        result.push_back(-1); 
    }else{
        int ub = upperBound(input,target);
        result.push_back(lb);
        result.push_back(ub -1);
    }

    cout<<result[0]<<" "<<result[1]<<endl;
    
    return 0;
}