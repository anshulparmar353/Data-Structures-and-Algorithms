#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int val=0;
    for(int i=N; i>0; i/=2){
        for(int j=0; j<i; j++){
            cout<<val<<" ";
            val++;
        }
    }
    return 0;
}