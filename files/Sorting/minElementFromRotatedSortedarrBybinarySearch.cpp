#include<iostream>
#include<vector>
using namespace std;

int findMinEleInRotatedSorted(vector<int> &input){
    // when arr size is 1
    if(input.size() == 1) return input[0];

    //when arr is sorted
    int lo = 0 , hi = input.size()-1;
    if(input[lo] < input[hi]){
        return lo;
    }

    // when arr is rotatedsoredarr
    while (lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(input[mid] > input[mid+1]) return mid+1;
        if(input[mid] > input[lo]){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}
int main(){

    vector<int> input;

    int n;
    cin>>n;

    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        input.push_back(x);
    }

    cout<< findMinEleInRotatedSorted(input);
    
    return 0;
}