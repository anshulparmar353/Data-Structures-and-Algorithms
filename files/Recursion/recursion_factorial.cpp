#include <iostream>
using namespace std;

int f(int n){
    // base case
    if (n == 1)
        return 1;
    // assumption
    return f(n - 1) * n;
}
int main(){
    cout << f(5);
    return 0;
}