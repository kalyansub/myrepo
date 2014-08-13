#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string inStr="abc def ghi jk lmnop  hello";

  string sub;
  size_t index;


  index = inStr.find("el");     
  sub = inStr.substr (index);   

  cout<<"index = "<<index<<"\n";
  cout<<sub<<"\n";

  return 0;
}
