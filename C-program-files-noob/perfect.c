#include<stdio.h>
void is_perfect(int num){
    int sum=0,i;
    for(i=1;i<num;i++)
        if(num%i==0) 
        {sum+=i;}
    if(sum==num) 
    {printf("The number is perfect");}
    else 
    {printf("The number is not perfect");}
    
}

int main(){
    int n,sum=0;
    printf("Enter a number \n");
    scanf("%d",&n);
    is_perfect(n);
    return 0;
}