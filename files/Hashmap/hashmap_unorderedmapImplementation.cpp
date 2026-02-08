#include<iostream>
#include<unordered_map>
using namespace std;
                    
int main(){

    unordered_map<int,string> m;

    m.insert({1,"riya"});
    m.insert({5,"riya"});
    m.insert({2,"riya"});
    m.insert({3,"riya"});

    m[0]="andju";
    
    for(auto ele: m){
        cout<<"Roll no:"<<ele.first<<" ";
        cout<<"Name:"<<ele.second<<endl;
    }
    
    return 0;
}