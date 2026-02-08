#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

bool checkAllAlphabets(string str){

    if(str.length() < 26){
        return false;
    }

    transform(str.begin(),str.end(),str.begin(),::tolower);

    set<char> alphabets;

    for(auto ch : str){
        alphabets.insert(ch);
    }

    return (alphabets.size()==26);


}
                    
int main(){

    string input;
    cin>>input;

    if(checkAllAlphabets(input)){
        cout<<"yes";
    }else{
        cout<<"NO";
    }cout<<endl;
    
    return 0;
}