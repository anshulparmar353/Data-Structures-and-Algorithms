#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommanPrefix(vector<string> &str){

    //keeping first string constant 
    string s1 = str[0];

    int ans_length = s1.size();
    
    for(int i=1; i<str.size(); i++){

        int j=0;

        // finding the common prefix string length
        while (j<s1.size() && j<str[i].size() && s1[j] == str[i][j]){
            j++;
        }
    
        //updating length of ans string
        ans_length = min(ans_length, j);
        
    }
    string ans = s1.substr(0,ans_length); 
    return ans;
}


int main(){

    int n;
    cout<<"Entet number of strings: ";
    cin>>n;

    cout<<"enter the strings: ";

    vector<string>str(n);
    for(int i=0; i<n; i++){
        cin>>str[i];
    }

    cout<<" The longest comman prefix: "<<longestCommanPrefix(str)<<endl;
    
    return 0;
}