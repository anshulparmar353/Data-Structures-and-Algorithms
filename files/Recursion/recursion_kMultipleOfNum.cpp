#include<iostream>
using namespace std;
void f(int num,int k){
    //base case
    if(k==0) return;
    //self work 
    f(num,k-1);
    cout<<(num*k)<<" ";
}
int main(){
    f(5,10);
    
    return 0;
}