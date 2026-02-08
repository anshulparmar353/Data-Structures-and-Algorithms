#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommanPrefix(vector<string> &str){

    //sort the strings
    sort(str.begin(),str.end());

    //first string
    string s1 = str[0];
    int i=0;

    //last string
    string s2 = str[str.size()-1];
    int j=0;

    string ans = "";

    while(i<s1.size() && j<s2.size()){

        if(s1[i]==s2[j]){
            ans+=s1[i];
            i++;
            j++;
        }else{
            break;
        }
    }
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