/* Implement the strstr() C library function: given a super string "haystack",
 * the function has to find the first occurrence of a sub string "needle" in the super string.
 * If either of the strings is NULL, it returns NULL and the super string is always longer
 * that the sub string */

#include <stdio.h>
#include <assert.h>
#include <string.h>


int length(char* str)
{
    int len = 0;

    while(*str++ != '\0')
    {
        len++;
    }
    return len;
}

char* findString(const char *haystack, const char *needle)
{
    const char *a = haystack, *b = needle;  
    for (;;)  
    {
        if (!*b)
        {
            return (char *)a;  
        }
        else if (!*a) 
        {
           return NULL;  
        }
        else if (*a++ != *b++)
        { 
            a = ++haystack;
            b = needle;
        }  
    }
}

int main(int agrc, char* argv[])
{
    char needle[4];
    char haystack[10];
    char* foundStr;

    printf("Enter the super string:\n");
    scanf("%s", haystack);
    printf("Enter the sub string : \n");
    scanf("%s", needle);
    foundStr = findString(haystack, needle);
    if (foundStr) printf("found %s\n", foundStr);
    return 0; 
}
