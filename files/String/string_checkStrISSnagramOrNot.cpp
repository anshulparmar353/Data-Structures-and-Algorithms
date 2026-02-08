#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagram(string &str1, string &str2){

    //create a freq array
    vector<int> freq(26,0);

    // if the length of both string is not same then return false
    if(str1.length() != str2.length()){
        return false;
    }

    //store freq of char in str1 and str2
    for(int i=0; i<str1.length(); i++){
        freq[str1[i]-'a']++; // for str1 , we are incrementing freq of char
        freq[str2[i]-'a']--; // for str2 , we are decrementing freq of char
    }

    // checking if freq of every char is 0 or not
    for(int i=0; i<26; i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}


int main(){

    string str1,str2;
    cin>>str1>>str2;

    if(isAnagram(str1,str2)){
        cout<<" The given string is anagram";
    }else{
        cout<<" The given string is not an anagram";
    }

    return 0;
}