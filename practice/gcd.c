/* An algorithm to recursively compute the Greatest Common Divisor (GDC) of two intgers.
 * $Author$: Kalyan Subramanian
 * $Date$: Nov 2, 2014
 * $email$: kalyan dot sub at gmail dot com
 */

#include <stdio.h>

int gcd(int a, int b)
{
    return (b == 0)?a:gcd(b, a%b);
}


int main(int argc, char* argv[])
{
    int num1, num2; 

    printf("Enter number 1 (numerator) for GCD: \n");
    scanf("%d", &num1);
    printf("Enter number 2 (denominator) for GCD: \n");
    scanf("%d", &num2);

    printf("Evaluated the GCD(%d, %d) as %d\n", num1, num2, gcd(num1, num2));

    return 0;
}
