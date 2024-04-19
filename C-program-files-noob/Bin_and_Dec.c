#include "binario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    int n;float f;

    printf("\nEnter the integer to convert into binary:-\t");
    scanf("%d",&n);
    char* bin1 =dci2bn(n);  
    printf("%s",bin1);
    free(bin1); //free the dynamically allocated memory


    printf("\nEnter the float to convert into binary:-\t");
    scanf("%f",&f);
    char* bin2 =dcf2bn(f);
    printf("%s\n",bin2);
    free(bin2); //free the dynamically allocated memory
}