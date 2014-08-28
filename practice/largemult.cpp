/* FB Interview problem: given 2 input arrays of characters representing large inetgers,
   write a function to produce the product of the two arrays a and b as a third array of
   characters c, which represents the product as an integer.

   $Author$: Kalyan Subramanian
   $Date$: Aug 27, 2014
   $email$: kalyan dot sub at gmail

*/

#include <iostream>
#include <cassert>
#include <cstring>

using std::cout;
#define toAscii(A,len)   for(int i=0; i<len; A[i++]+='0');
#define fromAscii(A,len) for(int i=0; i<len; A[i++]-='0');

int inline toint(char x)
{
    return (int)(x - '0');
}

char inline tochar(int i)
{
    return (char)(i + '0');
}

char * multiply(char *A, char*B)
{
	int n= strlen(A);
	int m = strlen(B);
	char * res = (char*) new char[(sizeof(char)*n+m+1)];
        assert(res != NULL);
	memset(res, 0, sizeof(char)*n+m+1);
	fromAscii(A,n);
	fromAscii(B,m);
	for(int i=n-1; i>=0; i--)
		for(int j=m-1; j>=0; j--)
		{
			res[i+j+1]+=(A[i] * B[j]);
			res[i+j]+=res[i+j+1]/10;
			res[i+j+1] = res[i+j+1]%10;
		}
	toAscii(res, n+m+1);
	res[n+m]='\0';
	return res;
}

void largemult(char* a, char* b, char* res)
{
    int lenA = sizeof(a)/sizeof(a[0]);
    int lenB = sizeof(b)/sizeof(b[0]);
    int lenC = lenA + lenB;
    int *c = new int[lenC];
    int i, j, k;

    assert(c!= NULL);
    std::memset(c, 0, sizeof(int)*lenC);

    for( i = lenA-1; i >= 0; i--)
    {
        for( j= lenB-1; j >= 0; j--)
        {
            c[i+j+1] += (toint(b[j])*toint(a[i]));
        }
    }
    for(i = lenC-1; i >= 0; i--)
    {
        cout << "i = " << i << "lenC = " << lenC <<\
             "c[" << i << "] = " << c[i] << "\n"; 
        if (c[i] >= 10) // deal with carry here
        {
            c[i-1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    
    i = 0;
    while( c[i] == 0 )
    {
       i++;
       cout << "**** c[" << i << "] = " << c[i] << "\n";
    }

    j = 0;
    while (i < lenC)
    {
       res[j] = tochar(c[i]);
       cout << "res[" << j << "]= " << res[j] << " char c[" << i << "]= " << c[i] << "\n";
       i++; j++; 
    }
    res[j] = 0;

    delete[] c;
}

int main(int argc, char* argv[])
{
    char* a = const_cast<char*>("1234");
    char* b = const_cast<char*>("5678");
    char* c = new char[strlen(a) + strlen(b)]; 
    assert( c!= NULL );

    //largemult(a, b, c);    
    //cout << "Product of a: [" << a << "] and b: [" << b << "] is c: [" << c << "]\n";

    c = multiply(a, b);
    cout << "Multiply gives: a: [" << a << "] and b: [" << b << "] is c: [" << c << "]\n";


    delete [] c;
    
    return 0;
}
