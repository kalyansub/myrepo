/*CtCI problem 1: write a function to find if all chars in a string are unique; assume ASCII string, i.e. 128 chars in a set */

#include <stdio.h>
#include <string.h>

typedef enum {true = 1, false = 0}bool;

int charPresent[256]; //declared global intentionally  - it will get initiaized with zero int vals automagically!

bool lowfatCheck(char* str, int len)
{
      int val =0, checkBitVector = 0;
      int i;
      for(i = 0; i < len; i++)
      {
          val = (int)(str[i] - 'a');
          printf("val = %d\n", val);
          if(checkBitVector & (1 << val))
          {
              return false;
          }
          checkBitVector|= (1<< val);
      }
      return true;
}

bool checkIfAllCharsUnique(char* str, int len)
{
    int i; 

    printf("len = %d, str = %s\n", len, str);
    if (len > 128)
    {
       return false;
    }
    else
    {
        for( i = 0; i < len; i++)
        {
            charPresent[str[i]]++;
            if (charPresent[str[i]] > 1) // frequency of occurence of the character is > 1 means the string doesn't contain all unique characters
            {
                printf("found duplicates of : %c at %d, so NOT unique!\n", str[i], i);
                return false;
            }
        }
    }
    return true;
}
int main(int argc, char*argv[])
{
    char str[] = {'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'x', '\0'};
    //char str[7];
   // strcpy(str, "zzzzzz");
    char* result[3] = {"yes", "no"};

    int len = sizeof(str)/sizeof(str[0]);

    printf("check unique function returned: %s\n", (checkIfAllCharsUnique(str, len)?result[0]:result[1]) );
   
      printf("*** lowfatCheck returned: %s\n", (lowfatCheck(str, len)?result[0]:result[1]));
    return 0; 
}
