#include <iostream>
using namespace std;
int f(int *arr, int idx, int n)
{
    // base case
    if (idx == n - 1) return arr[idx];
    // self work
    return arr[idx] + f(arr, idx + 1, n);
}

int main()
{
    int arr[] = {5, 4, 5, 4, 1};
    int n=5;
    cout << f(arr, 0, n);

    return 0;
}