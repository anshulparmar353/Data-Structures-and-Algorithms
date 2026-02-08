#include<iostream>
#include<set>
using namespace std;
                    
int main(){

    set<int , greater<int>> st;

    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);

    for(auto value : st){
        cout<<value<<" ";
    }cout<<endl;


    cout<<" BY ITERATOR : "<<endl;
    set<int>::iterator itr;
    for(itr = st.begin(); itr!=st.end(); itr++){
        cout<<*itr<<" ";
    }cout<<endl;
    
    
    return 0;
}