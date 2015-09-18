/* Problem statement: given a mxn grid, with a robot that starts at the top left corner,
 * find the total number of paths that the robot could travel to reach the bottom right corner in the 
 * mxn grid. The constraints are: at each step, the robot can move either one step to the right, or one 
 * step down, it cannot move left or up or diagonally and also, it can't back track. 
 * The first attempt is a naive recursive implementation of a countpaths() function that is exponential 
 * in complexity; this is because, the same paths are computed over and over again as subproblems!
 * The classic way to avoid this is to use Dynamic Programming (DP) with memoization. 
 * The second function, countPathsDP() implements a DP solution that will reduce the complexity 
 * to polyonimal time, O(m*n). Note that, the total number of paths is (m-1 + n-1)!/((m-1)!*(n-1)!).
 *   $Author$: Kalyan Subramanian
 *   $email$: kalyan dot sub at gmail
 *   $Date$:  Oct 7th, 2014
*/
#include <iostream>
using namespace std;
typedef unsigned long ULONG;

enum {MAX_ROWS = 25, MAX_COLS = 25};

// First use plain recursion: a bute force solution:

ULONG countPaths(int m, int n)
{
    if ( (m == 1) || (n == 1) )
    {
        return 1;
    }
    else
    {
        // recursive count of paths (down, right) plus count of paths (right, down)
        return countPaths(m, n-1) + countPaths(m-1, n);
    } 
}

// Recomputing many of the sub problem paths can be avoided by DP with memoization: cache the recently
// computed paths and first check if a path already exists in the cache before recomputing it:
//
ULONG countPathsDP(int m, int n)
{
    ULONG cache[m][n]; // this is a memonization table to store subproblem paths already done
    int i, j;

   for(i = 0; i < m; i++)
   {
    cache[i][0] = 1; // there is only one path to reach any cell in the first row: (see https://www.youtube.com/watch?v=9QduzzW10uA) 
   }
   for(j = 0; j < n; j++)
   {
       cache[0][j] = 1; // there is only one path to reach any cell in the first column :
   }

   for(i = 1; i < m; i++)
   {
      for(j = 1; j < n; j++)
      {
          cache[i][j] = cache[i][j-1] + cache[i-1][j];
      }
   }
   cout << " i = " << i << ", j = " << j << endl;
   return cache[i-1][j-1]; 
}

inline ULONG min(int x, int y)
{
    return (x)<=(y)?(x):(y); 
}

/*
void printMatrix(int arr[MAX_ROWS][MAX_COLS], int m, int n)
{
    for(int r = 0; r < m; r++)
    {
        for(int c = 0; c < n; c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
*/


ULONG minCost(int cost[][MAX_COLS], int m, int n)
{
    int i, j;
    ULONG dpCost[MAX_ROWS][MAX_COLS];

    dpCost[0][0] = cost[0][0];

    for(i = 1; i <= m; i++)
    {
        dpCost[i][0] = dpCost[i-1][0] + cost[i][0];
    }
    for(j = 1; j <= n; j++)
    {
        dpCost[0][j] = dpCost[0][j-1] + cost[0][j];
    }
 
    for(i = 1 ; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            dpCost[i][j] = min(dpCost[i-1][j], dpCost[i][j-1]) + cost[i][j];
        }
    }

    cout << "In minCost(), m = " << m << ", n = " << n << "dpCost[" << m << "][" << n << "]="\
         << dpCost[m][n] << endl;

    return dpCost[m][n];
}

int main(int argc, char* argv[])
{
    int m, n; 
    int dp = 0;

    cout << "How many rows (m) and columns (n) in the grid?" << endl;
    cout << "Enter m: " << endl;
    cin >> m;
    cout << "Enter n: " << endl;
    cin >> n;
    cout << "Run Brute Force (0) or DP algorithm (1)?\n";
    cin >> dp; 

    if (dp == 0)
    {
        cout << "Brute force recursive Count of paths for m = " << m << ", n = " << n << " is : " \
             <<  countPaths(m,n) << endl;
    }
    else
    {
        cout << "Using DP implementation gives: " << countPathsDP(m,n) << " paths" << endl;
    }

    m = MAX_ROWS;
    n = MAX_COLS;
    int cost[25][25];
    /*
    int **cost = new int*[m];
    for(int i = 0; i < m; ++i)
    {
        cost[i] = new int[n];
    }
    */
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
             cost[i][j] = 1;
        }
    }

    //printMatrix(cost, m, n);

    ULONG shortestPath = minCost(cost, m-1,n-1);

    cout << "DP based minCost(" << m << "," << n << ") = " << shortestPath << endl;

    /*
    for(int i = 0; i < n; ++i)
    {
        delete [] cost[i];
    }
    delete [] cost;
    */

    return 0;
}
