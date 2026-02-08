#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool checkAnagramOrNot(string s1, string s2){

    if(s1.length()!=s2.length()){
        return false;
    }
    
    unordered_map<char,int> m;

    for(auto ch1: s1){
        m[ch1]++;
    }

    for(auto ch2: s2){
        if(m.find(ch2)==m.end()){
            return false;
        }else{
            m[ch2]--;
        }
    }

    for(auto ele: m){
        if(ele.second!=0){
            return false;
        }
    }

    return true;
}
                    
int main(){

    string s1,s2;
    cin>>s1>>s2;

    cout<<(checkAnagramOrNot(s1,s2)?"Anagram": "Not Anagram")<<endl;
    
    return 0;
}