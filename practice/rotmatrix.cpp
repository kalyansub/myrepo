// Write a function to rotate a given MxN matrix by 90 deg counterclockwise.
// Assume it is OK to allocate extra storage for result, i.e. not in-place result 

#include <iostream>
#include <cassert>
using std::cout;
using std::endl;


int** rotateMatrix90(int mat[][3], int rows, int columns)
{
    int** rot = new int*[rows];
    assert(rot != NULL);
    for(int i = 0; i < rows; ++i)
    { 
        rot[i] = new int[columns];
        assert(rot[i] != NULL);
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
    assert(rot180 != NULL);

    for(int i = 0; i < rows; ++i)
    {
         rot180[i] = new int[columns];
         assert(rot180[i] != NULL);
    }

    int** p = new int*[rows];
    assert(p != NULL);
    for(int i = 0; i < rows; ++i)
    {
        p[i] = new int[columns];
        assert(p[i] != NULL);
    }

    // Suppose the matrix has 'rows' # of rows and 'cols' # of columns; let c and r denote
    // the current column and row index; then, for a 180 deg ccw rotation, first reverse the 
    // row elements: a[0][0] = a[0][cols-1], a[0][1] = a[0][cols-2], ..., 
    // a[r][c] = a[r][cols -(c+1)]
    // Then reverse the column elements: a[0][0] = a[rows-1][0], a[1][0] = a[rows-2][0], ...
    // a[r][c] = a[rows -(r+1)][c]
    //

    cout << "In rotateMatrix180(): rows = " << rows << ", columns = " << columns << endl;
    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < columns; ++c)
        {
            int tmp               = mat[r][c];
            mat[r][c]             = p[r][columns - (c+1)];
            p[r][columns - (c+1)] = tmp;
        }
    }

    cout << "matrix after reversing rows: \n";
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            cout << p[i][j] << ", ";
        }
        cout << endl;
    }

    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < columns; ++c)
        {
            int tmp                 = p[r][c];
            rot180[r][c]            = p[rows - (r+1)][c]; 
            rot180[rows - (r+1)][c] = tmp; 
        }
    }

    cout << "matrix after reversing columns: \n";
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            cout << rot180[i][j] << ", ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; ++i)
    {
        if (p[i] != NULL ) delete [] p[i];
    }
    if (p!= NULL)
    {
        delete [] p;
    }

    return rot180;
}

int main(int argc, char* argv[])
{
    int  rows = 4, columns = 3;
    int matrix[4][3] = { 1, 2, 3,
                         4, 5, 6,
                         7, 8, 9,
                        10,11,12};

    cout << "Original Input matrix...\n";

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }

    int** res = rotateMatrix90(matrix, rows, columns);

    cout << "Rotate by 90deg result: " << endl;
    for(int i = 0; i < columns; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }

    for(int i = 0; i < columns; ++i)
    {
        if (res[i] != NULL ) delete [] res[i];
    }
    if (res!= NULL)
    {
        delete [] res;
    }

    int **res180 = rotateMatrix180(matrix, rows, columns);

    cout << "Rotate by 180deg result: " << endl;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            cout << res180[i][j] << ", ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; ++i)
    {
        if (res180[i] != NULL ) delete [] res180[i];
    }
    if (res180!= NULL)
    {
        delete [] res180;
    }

    return 0;
}
