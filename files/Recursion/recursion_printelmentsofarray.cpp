#include <iostream>
using namespace std;
void f(int *arr, int idx, int n)
{
    // base case
    if (idx == n)
        return;
    // self work
    cout << arr[idx] << endl;
    // assumption
    f(arr, idx + 1, n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5,idx;
    f(arr, idx , n);

    return 0;
}