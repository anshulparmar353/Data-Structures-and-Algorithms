#include<iostream>
using namespace std;

bool f(int *arr,int n ,int idx ,int x){

    //base case
    if(idx==n) return false;
    //assumption
    return (arr[idx]==x) || f(arr,n,idx+1,x);

}

int main(){
    int arr[6]={2,5,21,4,44,57};
    int n=6;
    int x=2;
    int idx;
    bool result = f(arr,n,0,x);
    if(result) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}