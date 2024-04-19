#include <stdio.h>

int fib_fast(int n) {
    // helper function ( recursive )
    int fib_fast_helper(int num, int prev, int curr) {
        if (num == 0) {
            return prev;
        } else {
            return fib_fast_helper(num-1, curr, prev+curr);
        }
    }
    return fib_fast_helper(n, 0, 1);
}

int main() {
    int input;
    puts("Enter the number you want to calculate fibonacci upto");
    scanf("%d",&input);
    int result = fib_fast(input);
    printf("%d\'th fibonacci number is %d\n",input, result);
    return 0;
}
