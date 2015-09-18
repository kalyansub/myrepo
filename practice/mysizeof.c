#include <stdio.h>
#define my_sizeof(x) ((char*)(&x + 1)-(char*)(&x))

int main(int argc, char* argv[])
{
     char c;
     int i;
     long l;
     float f;
     double d;

     printf("size of char = %d\n", (int)my_sizeof(c));
     printf("size of int = %d\n", (int)my_sizeof(i));
     printf("size of long = %d\n", (int)my_sizeof(l));
     printf("size of float = %d\n", (int)my_sizeof(f));
     printf("size of double = %d\n", (int)my_sizeof(d));

     return 0;
}
     
