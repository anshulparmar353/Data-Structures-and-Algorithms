#include<iostream>
#include<map>
#include<vector>
using namespace std;
                    
int main(){

    cout<<"enter elements number of elements: "<<endl; 
    int n;
    cin>>n;

    vector<int> input(n);
    for(int i=0; i<n; i++){
        cin>>input[i];
    }

    map<int,int> m;
    for(int i=0; i<n; i++){
        m[input[i]]++;
    }

    int sum = 0;
    for(auto ele: m){
        if(ele.second>1){
            sum+=ele.first;
        }
    }

    cout<<sum<<endl;
    
    return 0;
}