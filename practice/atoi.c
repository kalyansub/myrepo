/*  
 *  Implement the C standard library atoi() function call. Takes 
 *  an input alphanumeric string and returns the equivalent integer.  
     
    $Author$: Kalyan Subramanian
    $email$: kalyan dot sub at gmail
    $Date$: Sep 17, 2014 
*/
#include <stdio.h>
#include <assert.h>

typedef unsigned int UINT;
/* Function prototype */
int strToInt(char* str);

int strToInt(char* str)
{
    UINT i, n = 0;

    assert(str != NULL);
    printf("strToInt(): input string is: [%s]\n", str);
    for(i = 0 ; str[i] != '\0'; ++i)
    {
        n = n*10 + str[i] - '0';
        printf("n = %d, str[%d] = %d\n", n, i, (str[i] - '0')); 
    }
    return n;
}


int main(int argc, char* argv[])
{
    char str[4] = "723";
    int num = strToInt(str);

    printf("str = %s, num = %d\n", str, num);

    return 0;
}
