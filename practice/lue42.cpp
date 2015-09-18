#include <iostream>
using namespace std;

enum {SUCCESS = 0, MAGIC = 42, MAX = 99};

int main(int argc, char* argv[])
{
   int x;
   
   while (1)
   {
       cin >> x;
       cout << "Read: " << x << std::endl;
       if ( (x == MAGIC) || (x > MAX) )
           break;
   }

return SUCCESS;

}
