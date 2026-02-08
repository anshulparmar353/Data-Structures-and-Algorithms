#include<iostream>
#include<string>
#include<vector>
using namespace std;

string sortString(string &str){

    vector<int>freq(26,0);

    //storing freq of every char in string
    for(int i=0; i<str.length(); i++){
        int index = str[i] - 'a';
        freq[index]++;
    }

    //creating our sorting string 
    int j = 0;
    for(int i=0; i<26; i++){
        while(freq[i]--){
            str[j++] = i + 'a';

        }
    }
    return str;
}


int main(){

    string str;
    cin>>str;

    cout<<sortString(str)<<endl;
    
    return 0;
}