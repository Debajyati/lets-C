#include <stdio.h>

void main() {
    int len;
    printf("Enter the length of the array\n");
    scanf("%d",&len);
    int arr[len];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&arr[i]);
    }
    int count[6]={1,0,2,0,3,0};
    for (int j = 0; j < len; j++)
    {
        if(arr[j]/10<1) count[1]++;
        else if (arr[j]/10 >1 && arr[j]/10 <10) count[3]++;
        else if (arr[j]/10 >10 && arr[j]/10<100) count[5]++;
    }

        printf("{");
        for (int k = 0; k < 6; k++)
        {
            printf("%d,",count[k]);
        }
        printf("}\n");
    
}