#include <iostream>
#include <cstring>
using namespace std;

void arrangeFruits(char fruits[][60], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        // finding min element
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(fruits[min_index], fruits[j]) > 0)
            {
                min_index = j;
            }
        }
        // place the min elemnets at the beginning
        if (i != min_index)
        {
            swap(fruits[i], fruits[min_index]);
        }
    }
    return;
}

int main()
{

    char fruits[][60] = {"apple", "orange", "banana", "graphes", "pineapple", "kiwi"};

    int n = sizeof(fruits) / sizeof(fruits[0]);

    arrangeFruits(fruits, n);

    for (int i = 0; i < n; i++)
    {
        cout << fruits[i] << " ";
    }

    return 0;
}