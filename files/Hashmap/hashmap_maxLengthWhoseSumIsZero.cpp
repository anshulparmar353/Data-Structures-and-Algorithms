#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

int findmaxLengthWhoseSumIsZero(vector<int> &v){

    unordered_map<int,int> m;

    int prefixsum = 0;
    int maxlength = INT_MIN;
    for(int i=0; i<v.size(); i++){
        prefixsum += v[i];

        if(prefixsum==0){
            maxlength++;
        }

        if(m.find(prefixsum)!=m.end()){
            maxlength = max(maxlength , i - m[prefixsum]);
        }else{
            m[prefixsum] = i;
        }
    }
    return maxlength;
}
                    
int main(){

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<findmaxLengthWhoseSumIsZero(v)<<endl;
    
    return 0;
}