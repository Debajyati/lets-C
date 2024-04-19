#include<stdio.h>
#include<math.h>
// Note : The program can not handle hex code(A,B,C,D,E,F)
int main(){
    int num, radix, decimal=0, rem, i=0;

    printf("Enter the number: ");
    scanf("%d",&num);

    printf("Enter the radix: ");
    scanf("%d",&radix);

    while (num!=0){
        rem=num%10;
        num/=10;
        decimal+=rem*pow(radix,i);
        i++;
    }

    printf("Decimal Equivalent: %d",decimal);

    return 0;
}
