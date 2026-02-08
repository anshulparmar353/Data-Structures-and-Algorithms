#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4};
    int x=9;
    int n=4;
    int i=0;
    int j=n-1;
    bool flag=false;
    while(i<j){
        if(arr[i]+arr[j]==x){
            flag=true;
            break;
        }
        else if(arr[i]+arr[j]<x){
            i++;
        }
        else{
            j--;
        }
    }

    if(flag==true) cout<<"YES";
    else cout<<"No";
    return 0;
}