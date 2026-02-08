#include<iostream>
#include<deque>
using namespace std;
                    
int main(){
    
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.pop_back();
    dq.pop_front();
    dq.push_back(3);

    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }cout<<endl;
    
    return 0;
}