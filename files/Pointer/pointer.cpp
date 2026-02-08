#include<iostream>
using namespace std;
int main(){
    
    int x=11;
    int *ptr=&x; // pointer intialisation
    cout<<" address of x :  "<<ptr<<endl;
    cout<<" value of x :   "<<*ptr<<endl;


    // sum by pointers
    int y=12;

    int *ptrx=&x;
    int *ptry=&y;
    int result;
    int *ptr_result=&result;

    *ptr_result=*ptrx+*ptry;

    cout<<"sum by result :   "<<result<<endl;
    cout<<"sum by pointer :    "<<*ptr_result;
     
    return 0;
}