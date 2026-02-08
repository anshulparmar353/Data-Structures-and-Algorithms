#include<iostream>
#include<set>
#include<vector>
using namespace std;
                    
int main(){

    int n,m;
    cin>>n>>m;
    cout<<"enter elements of v1: "<<endl;
    vector<int> v1(n);
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    cout<<"enter elements of v2: "<<endl;
    vector<int> v2(m);
    for(int i=0; i<m; i++){
        cin>>v2[i];
    }

    int ans = 0;
    set<int> s1;

    for(auto ele: v1){
        s1.insert(ele);
    }

    for(auto ele: v2){
        if(s1.find(ele)!=s1.end()){
            ans+=ele;
        }
    }

    cout<<ans<<endl;

    
    return 0;
}