#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {1, 5, 9, 5};

    cout << arr << " " << (arr + 1) << endl;
    cout << *arr << " " << *(arr + 1) << endl;
    return 0;
}