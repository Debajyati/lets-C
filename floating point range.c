#include <stdio.h>
void main(){
    float num;
    printf("Enter the floating point value: ");
    scanf("%f",&num);
    if(num>=0 && num<=30)
    printf("\nIt is in the range from 0 to 30\n");

    else if(num>30 && num<=50)
    printf("It is in the range from 30 to 50\n");

    else if(num>50 && num<=80)
    printf("It is in the range from 50 to 80\n");

    else if(num>80 && num<=100)
    printf("It is in the range from 80 to 100\n");

    else printf("Wrong Input");
}