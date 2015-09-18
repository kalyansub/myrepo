#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <assert.h>

#define min(a, b) ((a) <= (b) ? (a):(b) )


void lastAccessTime(char *filePath, time_t* rawtime);

void lastAccessTime(char *filePath, time_t* rawtime)
{
    struct stat attrib;
    stat(filePath, &attrib);
    char buf[96];
    struct tm* timestamp;
    struct tm tmp;

    timestamp = localtime(&(attrib.st_ctime));

    printf("Year = %d\n", timestamp->tm_year);
    printf("Month = %d\n", timestamp->tm_mon);
    printf("Day = %d\n", timestamp->tm_mday);

   /* strftime(buf, 80, "%x - %I:%M%p", timestamp);*/


   /*
    sscanf(buf, "%02d/%02d/%02 - %02d:%02d:%02d", \
           &tmp.tm_mday, &tmp.tm_mon, &tmp.tm_year, \
           &tmp.tm_hour, &tmp.tm_min, &tmp.tm_sec );
    */

   *rawtime = mktime(timestamp);
}


int main(int argc, char* argv[])
{
    char f1[16];
    char f2[16];
    char f3[16];
    time_t actime1, actime2, actime3;
    double diff1, diff2, diff3, minimum; 
    time_t timeArray[3] = {actime1, actime2, actime3};
    int maxindex = 0;

    if (argc < 4)
    {
        printf("Usage: %s <file path1> <file path2> <file path 3>\n", argv[0]); 
    }
    else
    {
        strncpy(f1, argv[1], sizeof(argv[1]));      
        strncpy(f2, argv[2], sizeof(argv[1]));      
        strncpy(f3, argv[3], sizeof(argv[1]));      

        lastAccessTime(f1, &actime1);
        lastAccessTime(f2, &actime2);
        lastAccessTime(f3, &actime3);
    } 
    /*
    printf(ctime(&actime1)); 
    printf(ctime(&actime2)); 
    printf(ctime(&actime3)); 
    */

   if ( diff1 = difftime(timeArray[maxindex], timeArray[1]) > 0 )
   {
       printf("diff %d and 1 = %g\n", maxindex, diff1);
       maxindex = 1;
   }
   if ( diff2 = difftime(timeArray[maxindex], timeArray[2]) > 0 )
   {
       printf("diff %d and 1 = %g\n", maxindex, diff2);
       maxindex = 2;
   }
      
   printf("The most recently accessed file is %s\n", argv[maxindex+1]); 

   return 0;
}
