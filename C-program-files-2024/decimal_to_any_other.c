#include<stdio.h>

void convert(int num, int radix);

int main()
{
    int num, radix;
    printf("Enter the decimal number: ");
    scanf("%d", &num);
    printf("Enter the radix: ");
    scanf("%d", &radix);

    printf("The number %d in radix %d is: ", num, radix);
    convert(num, radix);
    return 0;
}

void convert(int num, int radix)
{
    char hex[] = "0123456789ABCDEF";

    if(num >= radix)
        convert(num/radix, radix);

    if(radix == 16)
        printf("%c", hex[num%radix]);
    else
        printf("%d", num%radix);
}
