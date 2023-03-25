#include <stdio.h>

int main() {
    int a,b,c;
    printf("Marks obtained in english?(in pecentage)\n");
    scanf("%d",&a);

    printf("Marks obtained in Maths?(in pecentage)\n");
    scanf("%d",&b);

    printf("Marks obtained in Programming?(in pecentage)\n");
    scanf("%d",&c);

    if (a>=33 && b>=33 && c>=33 && (a+b+c)/3 >= 40)
        printf("student passed");
    
    else printf("student failed");
    return 0;
}