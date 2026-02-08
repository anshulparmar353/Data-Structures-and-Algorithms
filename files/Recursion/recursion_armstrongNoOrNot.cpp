#include <iostream>
using namespace std;
int power(int p, int q){
    // base case
    if (q == 0) return 1;
    if (q % 2 == 0){
    // if q is even
        int result = power(p, q / 2);
        return result * result;
    }else{
        // if q is odd
        int result = power(p, q / 2);
        return p * result * result;
    }
}

int f(int n, int d){
    // base case
    if (n == 0) return 0;
    // assumption
    return power(n % 10, d) + f(n / 10, d);
}

int main(){
    int n;
    cin >> n;
    int temp=n;

    int noOfDigit = 0;
    while(temp>0){
        temp/= 10;
        noOfDigit++;
    }
    int result = f(n, noOfDigit);

    if (result == n ){
        cout << "Yes";
    }else{
        cout << "NO";
    }
    return 0;
}