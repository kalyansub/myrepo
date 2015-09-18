#include <stdio.h>

int f(int a, int b);
void g(int c);

int f(int a, int b)
{
    return a+b;
}

void g(int c)
{
   int x;
   x = f(c, c);
   printf("x = %d in g()\n", x); 
}

int main(int argc, char* argv[])
{
    int a, b, c;
    a = 2; b = 3;
    c = f(a, b);
    g(c);
    
    return 0;
}

