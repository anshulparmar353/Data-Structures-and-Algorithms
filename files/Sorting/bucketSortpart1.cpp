#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(float arr[], int size){

    //step1 : creating bucket size
    vector<vector<float>>bucket(size,vector<float> ());

    //step 2 : inserting elements into bucket
    for(int i=0; i<size;i++){
        int index=arr[i]*size;
        bucket[index].push_back(arr[i]);
    }

    //step 3 : sorting individual bucket
    for(int i=0; i<size; i++){
        sort(bucket[i].begin(),bucket[i].end());
    }

    //step 4 : combining elements from bucket
    int k=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<bucket[i].size(); j++){
            arr[k++]=bucket[i][j];
        }
    }
}
int main(){
    float arr[]={0.13,0.45,0.12,0.89,0.75,0.63,0.85,0.39};
    int size=sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr,size);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}