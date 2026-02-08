#include<iostream>
#include<set>
#include<string>
using namespace std;
                    
int main(){
    
    set<string> invitelist;

    cout<<" enter number of inviting friends :"<<endl;
    int n;
    cin>>n;
    
    while(n--){
        string name;
        cin>>name;
        invitelist.insert(name);
    }

    for(auto name: invitelist){
        cout<<name<<endl;
    }

    return 0;
}