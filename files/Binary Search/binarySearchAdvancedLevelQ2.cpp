#include<iostream>
#include<vector>
using namespace std;

bool canPlaceStudents(vector<int>&pos, int mid , int s){
    int n = pos.size();
    int studentsreqd = 1;
    int lastplaced = pos[0];

    for( int i=1; i<n; i++){
        if(pos[i]-lastplaced >= mid){
            studentsreqd++;
            lastplaced = pos[i];
            if(studentsreqd == s){
                return true; 
            }        
        }
    }
    return false;
}

int pathDistribution(vector<int>&pos, int s){

    int n = pos.size();
    int lo = 1;
    int hi =  pos[n-1] - pos[0];

    int  ans = -1;

    while (lo <= hi){
        int mid = lo +  (hi - lo)/2;
        if(canPlaceStudents(pos,mid,s)){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid -1;
        }
    }
    return ans;
}
int main(){
    
    vector<int> v;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int s;
    cin>>s;

    cout<<pathDistribution(v,s);


    return 0;
}
