#include<iostream>
#include<set>
using namespace std;
                    
int main(){

    multiset<int> ms;
    ms.insert(1);
    ms.insert(3);
    ms.insert(2);
    ms.insert(1);
    ms.insert(1);

    // ms.erase(1); // erase the num with duplicates

    for(auto value: ms){
        cout<<value<<" ";
    }cout<<endl;

    cout<<ms.count(1);

    
    
    return 0;
}