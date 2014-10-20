#include <stdio.h>

int countTrailingZerosInFactorial(int num)
{
    int zeros = 0, i;

    if (num < 5)
        return zeros;
    else
    {
       for(i = 5; num/i >=1; i*=5 )  
       {
           zeros += num/i;
           printf("zeros = %d, num = %d\n", zeros, num);
       } 
    }       
    return zeros;
}
       
int main(int argc, char* argv[])
{
    int num = 0;

    printf("Enter the number whose factorial you want to count trailing zeros in...\n");
    scanf("%d", &num);
    printf("%d trailing zeros in %d factorial\n", countTrailingZerosInFactorial(num), num);
    
    return 0;

}
