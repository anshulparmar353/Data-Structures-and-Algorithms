#include<iostream>
using namespace std;
int f(int i,int j, int m, int n){
    //base case
    if(i==m-1 and j==n-1) return 1;
    if(i>=m or j>=n) return 0;
    //assumption
    return f(i+1,j,m,n) + f(i,j+1,m,n);
}

int main(){
    cout<<f(0,0,2,3);
    return 0;
}