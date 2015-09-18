/* CtCI interview problem 1.2: write a function in C to reverse an ASCII string */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

char* reverse(char* input, int len)
{
    int i, j;
    char tmp = '\0';
    
#if __DEBUG
    printf("inputStr = [%s]\n", input);
    printf("len = %d\n", len);
#endif
   
    for(i = 0, j = len -1; i < len/2 && j > i;i++, j--)
    {
        tmp = input[i];
        input[i] = input[j];
        input[j]= tmp;
#if __DEBUG
        printf("i = %d, j = %d, tmp = %c\n", i, j, tmp);
#endif
    }
    return input;
}
int main(int argc, char* argv[])
{
    char* inputStr;
    int len = 0;

    inputStr = (char* )calloc(MAX, sizeof(char));
    if (inputStr == NULL)
    {
        printf("calloc() failed!\n");
        return -1;
    }

    printf("Enter your string that you want reversed: \n");
    fgets(inputStr, MAX, stdin); 
    len = strlen(inputStr);

    printf("reversed string is: %s\n", reverse(inputStr, len) );

    free(inputStr);

    return 0;
}

