#include <stdio.h>

int main() {
    //A=P*(1+rt)
    int A,P,i,t;
    float r;
    printf("the amount of Principal Balance,time(in years),annual rate of interest respectively:-\n");
    scanf("%d%d%f",&P,&t,&r);
    A=P*(1+r*t);
    printf("The final amount will be %d\n",A);
    i=A-P;
    printf("The amount of simple interest will be %d\n",i);
    return 0;
}