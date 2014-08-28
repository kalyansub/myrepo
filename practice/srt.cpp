/* FB Interview question: write a function to compute srt(x) without any library
   One idea is to use a binary search and compare root finding approach;
   a simpler approach than Newton Rhapson, but iterative as well. Will converge
   in N iterations as defined by tolerance specified in the error term.

   $Author$: Kalyan Subramanian
   $Date$: Aug 26, 2014
   $email$: kalyan dot sub at gmail

*/

#include <iostream>
using namespace std;

double sqroot(double x)
{
    double tol = 1.0E-09;
    
    double left = 0.0;
    double right = x;

    double guess = 0.0;
    double mid = (left + right)/2.0;

   while ( (right - left) > tol)
   {
       mid = (left + right)/2.0;
       guess =  mid;
       cout << "left = " << left << "mid = " << mid << "right =" << right << endl;

       if ( guess*guess < x)
           left = guess;
       else
           right = guess;
   } 
   return guess;
}
using namespace std;

int main(int argc, char* argv[])
{
    double x = 256.0;
    cout << "sqroot(" << x << ") = " << sqroot(x) << endl;

    return 0;
}
