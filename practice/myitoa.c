#include <stdio.h>
#include <string.h>

#define MAX 100

void reverse(char* str);
char* myitoa(int n);

int main(int argc, char* argv[])
{
    int n = 12343543;
    char* str;
    
    str = myitoa(n);
    printf("string reuslt of myitoa(%d) is : %s\n", n, str);
}

char* myitoa(int n)
{
    static char str[MAX];
    
    int i = 0;
    while(n)
    {
        str[i++]=(n%10)+'0';
        n=n/10;
    }
    str[i]='\0';
    reverse(str);

    return str;
}
