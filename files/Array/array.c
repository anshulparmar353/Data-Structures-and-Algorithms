#include <stdio.h>

int main()
{

    int array[5] = {1, 2, 3, 4, 5};

    int n = 5;
    for (int i = 0; i < n; i++)
    {
        printf("%d", array[i]);
        printf(" ");
    }
    printf("%d", array[0]);
    printf("%d", array[1]);
    printf("%d", array[2]);
    printf("%d", array[3]);
    printf("%d", array[4]);
    
    return 0;
}
