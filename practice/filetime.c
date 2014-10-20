#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Function prototype declarations: */
void lastAccessTime(char *filePath, time_t* rawtime);

/* lastAccesstime(): compute the last access time for given input file
 * Input: filePath : a string with the full path name to the input file
 * Ouptut: rawtime: a pointer to the raw time representing last access to the file
 */
void lastAccessTime(char *filePath, time_t* rawtime)
{
    struct stat attrib;
    stat(filePath, &attrib);
    char buf[96];
    struct tm* timestamp;
    struct tm tmp;

    timestamp = localtime(&(attrib.st_ctime));

    *rawtime = mktime(timestamp);
}

/* main: driver function that takes 3 input arguments on the command line to
 * Input: specify the three different files which will be compared for most recent access time
 * Output: prints out the path and name of the file which was most recently accessed
 * calls: lastAccessTime() defined above
 */
int main(int argc, char* argv[])
{
    char f1[16];
    char f2[16];
    char f3[16];
    time_t actime1, actime2, actime3;
    time_t timeArray[3];
    int maxindex = 0;

    if (argc < 4)
    {
        printf("Usage: %s <file path1> <file path2> <file path 3>\n", argv[0]); 
    }
    else
    {
        strncpy(f1, argv[1], sizeof(argv[1]));      
        strncpy(f2, argv[2], sizeof(argv[2]));      
        strncpy(f3, argv[3], sizeof(argv[3]));      

        lastAccessTime(f1, &actime1);
        lastAccessTime(f2, &actime2);
        lastAccessTime(f3, &actime3);
    } 

    timeArray[0] = actime1;
    timeArray[1] = actime2;
    timeArray[2] = actime3;

   if ( difftime(timeArray[maxindex], timeArray[1]) < 0 )
   {
       maxindex = 1;
   }
   if ( difftime(timeArray[maxindex], timeArray[2]) < 0 )
   {
       maxindex = 2;
   }
      
   printf(" %s\n", argv[maxindex+1]); 

   return 0;
}
