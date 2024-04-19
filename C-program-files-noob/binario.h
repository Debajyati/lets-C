#ifndef BINARIO_H
#define BINARIO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Converts a decimal integer into the corresponding binary number*/
char* dci2bn(int num) {
    
    int div = abs(num), count = 0, res[100000];
    while (div > 0) {
        res[count] = div % 2;
        div /= 2;
        count++;
    }
    char* binary = (char*)malloc((count + 3) * sizeof(char)); // Add an extra character for the negative sign, an extra character for the space, and an extra character for the null terminator
    int i;
    if (num >= 0) {
        binary[0] = '0';
        binary[1] = ' ';
        for (i = 0; i < count; i++) {
            binary[i + 2] = res[count - i - 1] + '0';
        }
        binary[count + 2] = '\0';
    } else {
        // In the custom representation for negative numbers, the most significant bit is 1, and there is a space between the 1 and the rest of the binary representation
        binary[0] = '1';
        binary[1] = ' ';
        for (i = 0; i < count; i++) {
            binary[i + 2] = res[count - i - 1] + '0';
        }
        binary[count + 2] = '\0';
    }
    return binary;
}

/*Converts a decimal float into the corresponding binary number*/
char *dcf2bn(float num) {
    char *binary = (char *)malloc(35 * sizeof(char));
    int *intPtr = (int *)&num;
    int i, index = 0;
    for (i = 0; i < 32; i++) {
        if ((*intPtr >> (31 - i)) & 1) {
            binary[index++] = '1';
        } else {
            binary[index++] = '0';
        }
        if (i == 0 || i == 8) {
            binary[index++] = ' ';
        }
    }
    binary[index] = '\0';
    return binary;
}

#endif