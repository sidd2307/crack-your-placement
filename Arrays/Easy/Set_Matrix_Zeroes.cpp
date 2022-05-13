// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Solution : TC: O(m*n) SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool firstRow = false;
        bool firstCol = false;

        // size of mat
        int m = matrix.size();    // col
        int n = matrix[0].size(); // row

        // check for first row
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
            {
                firstRow = true;
                break;
            }
        }

        // check for first col
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                firstCol = true;
                break;
            }
        }

        // check for all elements apart from first row/col
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // now do all zero work
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // now make use of firstRow to make all first row things 0
        if (firstRow)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }

        // now make use of firstCol to make all first col things 0
        if (firstCol)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};