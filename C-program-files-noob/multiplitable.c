#include <stdio.h>

int main() {
    int i,n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    for(i=1;i<=10;i++)
        printf("\n\n%2d * %2d =%2d\n",n,i,n*i);
    return 0;
}