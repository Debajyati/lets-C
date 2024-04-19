#include<stdio.h>

int main() {
	int n1, n2;
	
	printf("enter two numbers\n");

	printf("num1 = ");
	scanf("%d", &n1);
	
	printf("num2 = ");
	scanf("%d", &n2);

	// swap
	n1 = n1 + n2;
	n2 = n1 - n2;
	n1 = n1 - n2;

	printf("n1 = %d\n", n1);
	printf("n2 = %d\n", n2);
	
	return 0;
}