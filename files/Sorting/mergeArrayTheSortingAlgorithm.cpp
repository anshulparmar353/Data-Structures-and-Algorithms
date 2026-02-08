// #include<iostream>
// using namespace std;

// void mergeArray(int arr1[] ,int n1, int arr2[] ,int n2 , int arr3[] ){
    
//     int a=0;
//     int b=0;
//     int c=0;

//     while(a<n1 && b<n2){
//         if(arr1[a]<arr2[b]){
//             arr3[c++]=arr1[a++];
//         }else{
//             arr3[c++]=arr2[b++];
//         }
//     }

//     while(a<n1){
//         arr3[c++]=arr1[a++];
//     }
//     while (b<n2){
//         arr3[c++]=arr2[b++];
//     }
    

// }
// int main(){
//     int arr1[]={2,6,9,11};
//     int arr2[]={1,5,8};
//     int n1=sizeof(arr1)/sizeof(arr1[0]);
//     int n2=sizeof(arr2)/sizeof(arr2[0]);
    
//     int n3=n1+n2;
    
//     int arr3[n3];

//     mergeArray(arr1,n1,arr2,n2,arr3);

//     for(int i=0; i<n3; i++){
//         cout<<arr3[i]<<" ";
//     }cout<<endl;

//     return 0;
// }