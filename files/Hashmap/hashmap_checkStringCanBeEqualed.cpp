#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool checkCanBeEqual(vector<string> &v, int n){

    unordered_map<char,int> m;

    for(auto str: v){
        for(auto ch: str){
            m[ch]++;
        }
    }

    for(auto ele: m){
        if(ele.second%n!=0){
            return false;
        }
    }

    return true;
}
                    
int main(){

    int n;
    cin>>n;

    vector<string> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<(checkCanBeEqual(v,n)? "yes": "no") <<endl;

    
    return 0;
}