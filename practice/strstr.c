/* Implement the strstr() C library function: given a super string "haystack",
 * the function has to find the first occurrence of a sub string "needle" in the super string.
 * If either of the strings is NULL, it returns NULL and the super string is always longer
 * that the sub string */

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX_SEARCH_LENGTH 128
#define MAX_STRING_LENGTH 1024

int length(const char* str)
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
    const char *hp = haystack, *np = needle;  
    int orig_np_length = length(needle);
    for (;;)  
    {
        if (!*np)
        {
            printf("Reached the end of the sub string... np = %c, hp = %c\n", *np, *hp);
            return (char *)(np - orig_np_length);
        }
        else if (!*hp) 
        {
           printf("Reached the end of the super string...\n");
           return NULL;  
        }
        else if (*hp++ != *np++)
        { 
            hp = ++haystack;
            printf("hp = %c\n", *hp);
            np = needle;
            printf("np = %c\n", *np);
        }  
        printf("\n");
    }
    printf("Done!\n");
}

int main(int argc, char* argv[])
{
    char needle[MAX_SEARCH_LENGTH];
    char haystack[MAX_STRING_LENGTH];
    char* foundStr;

    printf("Enter the super string:\n");
    scanf("%s", haystack);
    printf("Enter the sub string : \n");
    scanf("%s", needle);

    foundStr = findString(haystack, needle);
    if (foundStr)
    {
        printf("found %s\n", foundStr);
    }
    else
    {
        printf("Search string : [%s] NOT found in super string : [%s]\n", needle, haystack);
    }

    return 0; 
}
