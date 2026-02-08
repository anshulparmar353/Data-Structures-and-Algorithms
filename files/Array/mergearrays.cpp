#include<iostream>
using namespace std;
int main(){

    int arr1[]={1,4,6,8,11};
    int arr2[]={2,3,5,7,10,14};
    int n=5;
    int m=6;

    int result[m+n];
    int i=0;
    int j=0;
    int k=0;


    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            result[k]=arr1[i];
            k++;
            i++;
        }else{
            result[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<n){
       result[k]=arr1[i];
        k++;
        i++;
    }
    while(j<m){
        result[k]=arr2[j];
        k++;
        j++;
    }
    for(int i=0; i<(m+n); i++)
    cout<<result[i]<<" ";

    return 0;
    
}
       

    
