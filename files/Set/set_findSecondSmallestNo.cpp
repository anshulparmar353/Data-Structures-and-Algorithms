#include<iostream>
#include<set>
#include<vector>
using namespace std;
                    
int main(){

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }


    set<int> st;

    for(auto ele: v){
        st.insert(ele);
    }

    auto itr = st.begin();
    itr++;

    cout<<"THE SECOND SMALLEST NUMBER IS:  "<<*itr<<endl;


    
    return 0;
}