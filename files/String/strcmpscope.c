#include<stdio.h>
#include<string.h>  

int main(){
    char str1[] = "hello";
    char str2[] = "world";

    // Correctly print the result of strcmp
    printf("%d", strcmp(str1, str2));

    return 0;
}
