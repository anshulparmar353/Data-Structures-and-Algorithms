#include<stdio.h>
int main(){
    int a,b,c;
    printf("enter the values");
    scanf("%d %d",&a,&b);
    c=a+b;
    printf("\n sum=%d",c);
    c=a-b;
    printf("\n sub=%d",c);
    c=a*b;
    printf("\n multi=%d",c);
    c=a/b;
    printf("\n div=%d",c);
    c=a%b;
    printf("\n modulus=%d",c);
    return 0;
}
    