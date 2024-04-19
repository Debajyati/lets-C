#include <stdio.h>

int main() {
    char c;
    printf("enter the letter here\n");
    scanf("%c",&c);

    if (c>=97&&c<=122)
    printf("it is a lowercase letter\n");

    else printf("its is an uppercase letter\n");
    return 0;
}