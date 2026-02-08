#include <iostream>
#include <vector>
using namespace std;
void f(int *arr, int n, int idx, int sum, vector<int> &result)
{
    // base case
    if (idx == n)
    {
        result.push_back(sum);
        return;
    }
    // assumption
    f(arr, n, idx + 1, sum + arr[idx], result);
    f(arr, n, idx + 1, sum, result);
}
int main()
{
    int arr[] = {1,3,5};
    int n = 3;
    vector<int> result;
    f(arr, n, 0, 0, result);
    for (int idx = 0; idx < result.size(); idx++)
    {
        cout << result[idx] << " ";
    }
    return 0;
}