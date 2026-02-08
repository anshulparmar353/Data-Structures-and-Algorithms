#include<iostream>
#include<map>
using namespace std;
                    
int main(){

    map<int,string,greater<int>> maping;

    maping[1] = "snsahu";
    maping[2] = "ansdj";

    maping.insert({4,"ghhg"});
    maping.insert(make_pair(9,"asjie"));

    cout<<"printing with for each loop"<<endl;
    for(auto ele: maping){
        cout<<ele.first<<"=>";
        cout<<ele.second<<endl;
    }

    cout<<"printing with iterator"<<endl;
    map<int,string>::iterator itr;
    for(itr = maping.begin(); itr!=maping.end(); itr++){
        cout<<itr->first<<"->"<<itr->second<<endl;
    }

    cout<<"printing with iterator in reverse order"<<endl;
    map<int,string>::reverse_iterator itr2;
    for(itr2 = maping.rbegin(); itr2!=maping.rend(); itr2++){
        cout<<itr2->first<<"->"<<itr2->second<<endl;
    }
    
    return 0;
}