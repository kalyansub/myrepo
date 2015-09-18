/* Print out the recurring digits in parantheses in a rational number p/q as m.(n), where n repeats to infinity; e.g. 1/3 = 0.(3), 2/9 = 0.(2). Supposedly a Google phone screen interview question.

  $Author$: Kalyan Subramanian
  $Date$: Sep 5th, 2014
  $email$: kalyan dot sub at gmail

*/

#include <iostream>
#include <iomanip> // Needed for cout precision and width functions
#include <cassert>
#include <cmath>

using std::cin;
using std::cout;


int main(int argc, char* argv[])
{
    int p, q, quotient;
    float fracrem = 0.0f;

    cout << "Enter the numerator p of the rational fraction p/q: \n";
    cin >> p;
    cout << "Enter the denominator q of the rational fraction p/q: \n";
    cin >> q;

    assert(q!=0);
    quotient = p/q;
    fracrem = floor((float)p/q *10);
    cout.precision(1);
    cout.width(1);
    cout << quotient << ".(" << fracrem << ")\n";
    
    return 0;
}
