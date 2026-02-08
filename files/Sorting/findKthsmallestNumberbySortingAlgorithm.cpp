#include<iostream>
#include<climits>
using namespace std;

int partition(int arr[],int l,int r){

    int pivot=arr[r];

    int i=l;

    for(int j=l; j<r; j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;

}


int kthSmallestNo(int arr[],int l, int r, int k){

    if(k>0 && k<=r-l+1){

        int pos = partition(arr,l,r);

        if(pos-l==k-1){
            return arr[pos];
        }
        else if(pos-l>k-1){
            return kthSmallestNo(arr,l,pos-1,k);
        }
        else{
            return kthSmallestNo(arr,pos+1,r,k-(pos-l+1));
        }

    }
    return INT_MAX;

}
int main(){

    int arr[]={1,4,7,5,2,8,6,3,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;

    cout<<kthSmallestNo(arr,0,n-1,k);
    
    return 0;
}