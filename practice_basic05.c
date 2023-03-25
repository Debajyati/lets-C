#include <stdio.h>

int main() {
    //Write a C program to find grade of a student given his marks based on below
    int marks;
    printf("Enter the marks obtained by the student\n");
    scanf("%d",&marks);

    if (marks<=100 && marks>90)
        printf("The student got grade A\n");

    else if (marks<=90 && marks>80)
        printf("The student got grade B\n");
    
    else if (marks<=80 && marks>70)
        printf("The student got grade C\n");

    else if (marks<=70 && marks>60)
        printf("The student got grade D\n");

    else if (marks<60)
        printf("Failed\n");
     
        
return 0;
}