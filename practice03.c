#include <stdio.h>

int main() {
    int i,num;
    printf("enter the number\n");
    scanf("%d",&num);

    for ( i = num; i>=0 ; i--)
    printf("\n%d",i);
    
    return 0;
}