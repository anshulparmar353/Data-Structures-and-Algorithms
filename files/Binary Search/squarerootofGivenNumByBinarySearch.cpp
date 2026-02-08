#include<iostream>
using namespace std;

int sqrByBinarySearch(int x){
    int lo=1;
    int hi=x;
    int ans=-1;

    while (lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(mid*mid == x){
            ans=mid;
        }else if(mid*mid <= x){
            ans=mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return ans;
    
}
int main(){

    cout<<sqrByBinarySearch(65);
    
    return 0;
}