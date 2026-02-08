#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(float arr[], int size){

   
    vector<vector<float>>bucket(size,vector<float> ());

    //STEP 1 : finding range
    float min_ele=arr[0];
    float max_ele=arr[0];
    for(int i=0; i<size; i++){
        max_ele=max(max_ele,arr[i]);
        min_ele=min(min_ele,arr[i]);

    }

    float range =(max_ele-min_ele)/size;

    //step 2 : inserting elements into bucket
    for(int i=0; i<size;i++){

        int index=(arr[i]-min_ele)/range;
        //boundary elements
        float diff = (arr[i]-min_ele)/range - index;

        if(diff==0 && arr[i]!=min_ele){
            bucket[index-1].push_back(arr[i]);
        }else{
            bucket[index].push_back(arr[i]);
        }
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
    float arr[]={0.13,0.45,0.12,0.89,10.75,0.63,0.85,10.39};
    int size=sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr,size);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}