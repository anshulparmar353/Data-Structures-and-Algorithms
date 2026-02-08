#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isIsomorphic(string &str1,string &str2){

    // if the length of given strings are different then return false
    if(str1.length()!=str2.length()){
        return false;
    }
    
    //create freq of char
    vector<int>freq1(128,-1);
    vector<int>freq2(128,-1);

    for(int i=0; i<str1.length(); i++){
        if(freq1[str1[i]] != freq2[str2[i]]){   // checking if the velue of char at idx i match in both strings
            return false;
        } 
        freq1[str1[i]] = freq2[str2[i]] = i;    // storing string position in  freq vectors for char at idx i 
    }
    return true;
}


int main(){

    string str1,str2;
    cin>>str1>>str2;

    if(isIsomorphic(str1,str2)){
        cout<<"The given strings are isomorphic";
    }else{
        cout<<"The given strings are not isomorphic";
    }
    
    return 0;
}