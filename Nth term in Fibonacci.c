#include <stdio.h>
int Fib(int n);

int main() {
    int n;
    printf("Enter the value of n in the sequence:\t");
    scanf("%d",&n);
    printf("\nThe nth element of the fibonacci series is %d ,if n=%d",Fib(n),n);
    return 0;
}
int Fib(int n){
    if (n>2)
    return Fib(n-1)+ Fib(n-2);
    
    else if (n==1 || n==2)
    return n-1;
}