#include <stdio.h>
#include <string.h>
// function definition to perform the slicing
void slice(const char* str, char* result, size_t start, size_t end)
{
    strncpy(result, str + start, end - start);
}
// main function to apply slicing on a string 
int main()
{
    const char* string = "Hey, Hello world";
    printf("%s\n", string);

    char slicedString[5] = "";
    slice(string, slicedString, 5, 5 + 4);
    printf("%s\n", slicedString);
}
