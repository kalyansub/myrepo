/*  
 * C function to reverse a string of characters.   
     
    $Author$: Kalyan Subramanian
    $email$: kalyan dot sub at gmail
    $Date$: Aug 20th, 2014 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* s);
 
#if 1

int main(int argc, char* agv[])
{
    char inputStr[] = "able was i ere i saw elba";
    printf("Input string: %s\n", inputStr); 
    reverse(&inputStr[0]);
    printf("Reversed string: %s\n", inputStr); 

    return 0;
}
#endif

void reverse(char* str)
{
    int i, j;
    char t;

    for (i = 0, j = strlen(str)-1; i< j; i++, j--)
    {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

