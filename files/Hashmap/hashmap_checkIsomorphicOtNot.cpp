#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool checkNoOneToManyMapping(string s1, string s2){

    unordered_map<char,char> m;

    for(int i=0; i<s1.length(); i++){
        if(m.find(s1[i])!=m.end()){
            if(m[s1[i]]!=s2[i]){
                return false;
            }
        }else{
            m[s1[i]] = s2[i];
        }
    }

    return true;
}

bool checkIsomorphicOrNot(string s1, string s2){
    
    if(s1.length()!= s2.length()){
        return false;
    }

    bool s1s2 = checkNoOneToManyMapping(s1,s2);

    bool s2s1 = checkNoOneToManyMapping(s2,s1);

    return s1s2 && s2s1;
}
                    
int main(){

    string s1,s2;
    cin>>s1>>s2;

    cout<<(checkIsomorphicOrNot(s1,s2)?"isomorphic": "not isomorphic")<<endl;
    
    return 0;
}