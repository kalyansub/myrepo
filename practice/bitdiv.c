/* FB interview question: implement division of integers using only bitwise operations */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum { false = 0, true = 1} boolean;

int divideBitwise( int a, int b);

int divideBitwise( int a, int b) // implements integer division a/b
{
    int aa = 0, ab =0, q = 1;
    boolean isNegative = false; // sign of quotient

    if( a == 0 ) return 0;

    assert(b != 0);

    if ( (a>0 && b<0)||(b>0 && a<0) ) //if a and b have opposite signs, quotient is -ve
    {
        isNegative = true;
    }
    // Get rid of negative signs if they exist:
    if ( a < 0 ) aa = -a;
    if ( b < 0 ) ab = -b;
    
    do
    {
        ab  <<=  1;
        q   <<=  1;
        printf("ab = %d, q = %d\n", ab, q);
    } 
    while( ab <= aa);

    (isNegative)? (q = -aa) : (q = aa);

   return q;
}
 
int main(int argc, char* argv[])
{
    int num, den;
    printf("Enter num: \n");
    scanf("%d", &num);
    printf("Enter den: \n");
    scanf("%d", &den);

    printf("%d div by %d = %d\n", num, den, divideBitwise(num,den ));

    return 0;
}
