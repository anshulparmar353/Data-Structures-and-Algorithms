#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>&v){
    int n=v.size();

    for(int i=1; i<n ; i++){
        int current_ele = v[i];
        int j=i-1;
        // finding the correct position for our current element
        while(j>=0 && current_ele < v[j]){
            v[j+1]=v[j];
            j--;
        }
        //insert current elements
        v[j+1]=current_ele;
    }
    return;
}

int main(){

    int n;
    cin>>n;

    vector<int>v(n);
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    insertionSort(v);

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}