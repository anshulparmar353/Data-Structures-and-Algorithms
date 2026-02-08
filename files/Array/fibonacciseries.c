#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int fibonacciseries[n];
    printf(" The Fibonacci Series:  ");
    fibonacciseries[0] = 0;
    fibonacciseries[1] = 1;
    printf("%d  ", fibonacciseries[0]);
    printf("%d  ", fibonacciseries[1]);

    for (int i = 2; i <= n; i++)
    {

        fibonacciseries[i] = fibonacciseries[i - 1] + fibonacciseries[i - 2];

        printf("%d  ", fibonacciseries[i]);
    }

    return 0;
}