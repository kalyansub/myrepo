/* Netflix Interview Question: given a number N, how many BSTs can be created with a sequence of
    numbers from 1 to N? Ans: It turns out the answer is the Nth Catalan number, referenced 
    in the article here: http://en.wikipedia.org/wiki/Catalan_number. But there is an easy way 
    to calculate this. Assume the input is 'numkeys', the number of keys given. Recursively 
    count the number of sub trees on the left and right, while adjusting the numkeys parameter 
    at each call, to be the remaining number of nodes after the last call. The running total
    would give the number of trees possible.
    $Author$: Kalyan Subramanian
    $email$: kalyan dot sub at gmail
    $Date$: Aug 21, 2014.
*/

#include <iostream>
using namespace std;

/* Straightforward implementation from recurrence relationship:
   C(0) =1, C(n+1) = Sum (i=0...n) of {C(i)*C(n-i)} for n > 0;
   recursive calls make this algorithm of complexity O(exponential)
*/
int catalan(int n)
{
    int sum = 0;
    //base case:
    if (n <= 1) return 1;
    //catalan(n) = running sum of catalan(i) * catalan(n-i-1);

    for(int i = 0; i < n; i++)
    {
        sum += catalan(i)* catalan(n-i-1);
    }
    return sum;
}

/* Slightly easier algorithm, don't need to know Catalan series */
int countBST(int numkeys)
{
    if (numkeys > 1)
    {
        int i = 1, sum = 0;

        for(i = 1; i <= numkeys; i++)
        {
            int numLeft = countBST(i-1);
            int numRight = countBST(numkeys-i);
            sum = sum + numLeft* numRight;
        }
        return sum;
    }
    else
       return 1;
}

int main(int argc, char* argv[])
{
    int num;
    cout << "Enter the number for which you want the #of BSTs computed:\n";
    cin >> num;
    cout << "BSTs that can be formed with numbers upto num:" << countBST(num) <<"\n";
    cout << "catalan number of order " << num << " is : " << catalan(num) << "\n";

    return 0; 
}
