// Write a function to rotate a given MxN matrix by 90 deg counterclockwise.
// Assume it is OK to allocate extra storage for result, i.e. not in-place result 

#include <iostream>
using std::cout;
using std::endl;


int** rotateMatrix90(int mat[][3], int rows, int columns)
{
    int** rot = new int*[rows];
    for(int i = 0; i < rows; ++i)
    { 
        rot[i] = new int[columns];
    }
     
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            rot[j][rows-i-1] = mat[i][j]; // first row of input becomes last column of output
        }
    }
    return rot;
}

int** rotateMatrix180(int mat[][3], int rows, int columns)
{
    int** rot180 = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
         rot180[i] = new int[columns];
    }
    // Suppose the matrix has 'rows' # of rows and 'cols' # of columns; let c and r denote
    // the current column and row index; then, for a 180 deg ccw rotation, first reverse the 
    // row elements: a[0][0] = a[0][cols-1], a[0][1] = a[0][cols-2], ..., 
    // a[r][c] = a[r][cols -(c+1)]
    // Then reverse the column elements: a[0][0] = a[rows-1][0], a[1][0] = a[rows-2][0], ...
    // a[r][c] = a[rows -(r+1)][c]
    //

    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < columns; ++c)
        {
            cout << "mat[" << c << "][" << r << "]=" << mat[c][r] << endl;
            cout << "columns -(c+1) = " << columns - (c+1) << endl;
            //rot180[r][columns -(c+1)] = mat[r][c];
        }
        cout << endl;
    }

    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < columns; ++c)
        {
            rot180[rows -(r+1)][c] = mat[r][c];
        }
    }
}

int main(int argc, char* argv[])
{
    int  rows = 4, columns = 3;
    int matrix[4][3] = { 1, 2, 3,
                         4, 5, 6,
                         7, 8, 9,
                        10,11,12};

    int** res = rotateMatrix90(matrix, rows, columns);

    for(int i = 0; i < columns; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }

    {
        int** res0 = rotateMatrix180(matrix, rows, columns);
    }

    for(int i = 0; i < columns; ++i)
    {
        if (res[i] != NULL ) delete [] res[i];
    }
    if (res!= NULL)
    {
        delete [] res;
    }

    for(int i = 0; i < columns; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
