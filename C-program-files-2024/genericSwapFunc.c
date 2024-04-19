#include <stdio.h>
#include <string.h>

// Swap function for generic types
#define SWAP(x, y) do { \
    size_t size = sizeof(x); \
    char tmp[size]; \
    memcpy(tmp, &x, size); \
    memcpy(&x, &y, size); \
    memcpy(&y, tmp, size); \
} while (0)

// Example(Instantiating) with integers
void swapIntegers(int *a, int *b) {
    SWAP(*a, *b);
}

// Example usage with structs
typedef struct {
    int x;
    double y;
} MyStruct;

// Instantiating 
void swapStructs(MyStruct *a, MyStruct *b) {
    SWAP(*a, *b);
}

int main() {
    // Swap integers
    int num1 = 5, num2 = 10;
    printf("Before swap: num1=%d, num2=%d\n", num1, num2);
    swapIntegers(&num1, &num2);
    printf("After swap: num1=%d, num2=%d\n", num1, num2);

    // Swap structs
    MyStruct struct1 = {1, 2.5};
    MyStruct struct2 = {3, 4.8};
    printf("Before swap: struct1=(%d, %.2f), struct2=(%d, %.2f)\n", struct1.x, struct1.y, struct2.x, struct2.y);
    swapStructs(&struct1, &struct2);
    printf("After swap: struct1=(%d, %.2f), struct2=(%d, %.2f)\n", struct1.x, struct1.y, struct2.x, struct2.y);

    return 0;
}