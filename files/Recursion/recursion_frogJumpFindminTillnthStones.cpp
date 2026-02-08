#include<iostream>
using namespace std;
int f(int *h,int n , int idx){
    //base case
    if(idx==n-1) return 0;
    if(idx==n-2) return f(h,n,idx+1) + abs(h[idx]-h[idx+1]);
    //assumption
    return min(f(h,n,idx+1) + abs(h[idx]-h[idx+1]),f(h,n,idx+2) + abs(h[idx]-h[idx+2]));
}

int main(){
    int h[]={5,10,10,15};
    int n=4;
    cout<<f(h,n,0);
    return 0;
}