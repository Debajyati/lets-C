#include <stdio.h>
#include <stdbool.h>
bool is_even(int num) {
    return num%2==0;
}
/*Using booleans to verify if a number is even or odd*/
int main() {
    int n;
    printf("Enter a number to check if it\'s even or not\n");
    scanf("%d",&n);
    printf("it is %s that %d is even",is_even(n)?"true":"false",n);
    return 0;
}
