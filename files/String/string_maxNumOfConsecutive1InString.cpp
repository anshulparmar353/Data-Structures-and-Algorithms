#include<iostream>
#include<string>
using namespace std;

int maxOnesInString(string &str,int k){

    int start = 0;
    int max_length = 0;
    int zero_count=0;
     
    for(int end=0; end<str.size(); end++){
        if(str[end]=='0'){
            zero_count++;
        }

        while(zero_count>k){
            if(str[start]=='0'){
                zero_count--;
                start++;
            }
        }
        max_length = max(max_length,end-start+1);
    }
    return max_length;
}
int main(){

    string str;
    cout<<"Enter the binary no: ";
    cin>>str;

    int k;
    cout<<"number of flips: ";
    cin>>k;

    cout<<maxOnesInString(str,k)<<endl;

    
    return 0;
}