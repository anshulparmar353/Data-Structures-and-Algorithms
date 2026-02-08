#include<iostream>
#include<set>
using namespace std;
                    
int main(){

    int n,p,q;
    cin>>n>>p>>q;

    set<int> st;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            int correct = i;
            int incorrect = j;
            int result = correct*p + incorrect*q;
            st.insert(result);
        }   
    }

    for(auto val: st){
        cout<<val<<" ";
    }cout<<endl;

    
    return 0;
}