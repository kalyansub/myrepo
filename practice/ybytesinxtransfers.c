/* given y bytes and you can transfer only x bytes at once..give a mathematical expression having only + - / * which gives the number of iterations to copy y bytes. ( dont try giving modulo operator answers )
 * $Author$: Kalyan Subramanian
 * $Date$: October 26, 2014
 * $emai$: kalyan dot sub at gmail dot com
 */
#include <stdio.h>

int main(int argc, char* argv[])
{
    int bytes, n_iter, actual_iters = 0;

    printf("Enter number of bytes to transfer per iteration: \n");
    scanf("%d", &bytes);
    printf("Enter the number of iterations for the transfer: \n");
    scanf("%d", &n_iter);

    actual_iters = (bytes + (n_iter - 1))/n_iter;

    printf("Actual # of iterations needed = %d\n", actual_iters);

    return 0;
}
