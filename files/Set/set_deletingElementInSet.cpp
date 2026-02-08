#include<iostream>
#include<set>
using namespace std;
                    
int main(){

    set<int> st;

    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);

    for(auto value : st){
        cout<<value<<" ";
    }cout<<endl;

    // // cout<<st.erase(4);
    // auto itr1 = st.begin();
    // // itr1++;
    // advance(itr1,3);
    // st.erase(itr1);

    auto itr1 = st.begin();
    auto itr2 = st.begin();
    advance(itr2,2);

    st.erase(itr1,itr2);


    cout<<" BY ITERATOR : "<<endl;
    set<int>::iterator itr;
    for(itr = st.begin(); itr!=st.end(); itr++){
        cout<<*itr<<" ";
    }cout<<endl;

    // st.erase(4);

    if(st.find(4)!=st.end()){
        cout<<"is present";
    }else{
        cout<<"element is not oresent";
    }cout<<endl;

    
    
    return 0;
}