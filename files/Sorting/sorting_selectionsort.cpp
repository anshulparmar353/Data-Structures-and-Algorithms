#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &v)
{
    int n = v.size();
    // finding min elment in unsorted array
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_index])
            {
                min_index = j;
            }
        }
        // putting min  element in beginning
        if (i != min_index)
        {
            swap(v[i], v[min_index]);
        }
    }
}
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i =0; i < n; i++)
    {
        cin >> v[i];
    }

    selectionSort(v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}