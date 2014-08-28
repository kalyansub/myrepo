/* Given a polynomial of the form cnxn + cn-1xn-1 + cn-2xn-2 +... + c1x + c0 and a value of x, find the value of polynomial for a given value of x. Here cn, cn-1, .. are integers (may be negative) and n is a positive integer. Input is in the form of an array say coeffs[] where coeffs[0] represents coefficient for xn and coeffs[1] represents coefficient for xn-1 and so on. The optimal
way to evaluate the polynomial and it's derivative simultaneously is to use Horner's method:
(((c[N]*x + c[N-1])*x + c[N-2])*x ....+ c[1])*x + c[0];
   $Author$: Kalyan Subramanian
   $Date$:  Aug 26, 2014
   $email$: kalyan dot sub at gmail 
*/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

typedef std::vector<int> IntVec;

struct Polynomial 
{
    Polynomial(IntVec& coeffs):m_Coeffs(coeffs), m_Order(0) {}
    int operator() (int x)
    {
        cout << "size of coeffs vector is : " << m_Coeffs.size() << std::endl;
        int j = m_Order = m_Coeffs.size() -1;
        cout << "m_Order = " << m_Order << "\n";
        int p = m_Coeffs[j];
        while( j > 0 )
        {  
            cout << "m_Coeffs[" << j << "] = " << m_Coeffs[j] << "\n";
            p = p*x + m_Coeffs[--j];
            cout << "p = " << p << "\n";
        }
        
        return p;
    }

    int dP_by_dx(int x) // first order derivative function...
    {
        int j = m_Order;
        int p = m_Coeffs[j];
        int dp = 0;
        while( j > 0 )
        {
            dp = dp*x + p;
            p = p*x + m_Coeffs[--j];
        }
        return dp;
    }

    int m_Order;
    IntVec m_Coeffs;
};

int main(int argc, char* argv[])
{
   IntVec newCoeffs;

   //Construct the polynomial : p(x) = -2x^3 + 3x^2 + x - 4
   newCoeffs.push_back(-4);// c[0]
   newCoeffs.push_back(1); // c[1]
   newCoeffs.push_back(3); // c[2]
   newCoeffs.push_back(-2);// c[3]

   int x = 3;
   Polynomial y = Polynomial(newCoeffs);
   cout << "Value of polynomial at x = 3 is : " << y(x) << "\n";
   cout << "derivative of the polynomial at x = 3 is " << y.dP_by_dx(x) << "\n";
   return 0;
}


