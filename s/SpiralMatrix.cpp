#include <vector>
#include "stdio.h"

using namespace std;

class Solution {
    public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
	    // Start typing your C/C++ solution below
	    // DO NOT write int main() function
	    vector<int > result;

	    int row_num = matrix.size() ;
	    if (row_num == 0)
		return result;

	    int col_num = matrix[0].size();


	    int loop_offset = 0;
	    int direction = 0; // 0, to right; 1, down, 2, to left, 3, up
	    int step = col_num;

	    while(step > 0)
	    {

		if( direction == 0)
		{
		    for(int i=loop_offset; i< col_num - loop_offset ; i++)
		    {
			result.push_back(matrix[loop_offset][i]);
		    }
		    step = row_num - 2*loop_offset -1;
		    direction = 1;
		}
		else if (direction == 1)
		{
		    for(int i=1+loop_offset; i< row_num- loop_offset; i++)
		    {
			result.push_back(matrix[i][col_num - loop_offset -1]);
		    }
		    step = col_num - 2*loop_offset -1;
		    direction =2 ;
		}
		else if (direction == 2)
		{
		    // bug here
		    for(int i= col_num - 2 - loop_offset; i>=loop_offset; i--)
		    {
			result.push_back(matrix[row_num - loop_offset-1][i]);
		    }
		    step = row_num - 2*loop_offset -2;
		    direction = 3;
		}
		else
		{
		    // bug -1
		    for(int i=row_num - loop_offset - 2; i>loop_offset; i-- )
		    {
			result.push_back(matrix[i][loop_offset]);
		    }                
		    direction = 0;
		    loop_offset++;
		    step = col_num -2*loop_offset;
		}
	    }
	    return result;
	}
};

int main(void)
{
    vector<int> a1;
    vector<int> a2;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(3);
    a2.push_back(8);
    a2.push_back(9);
    a2.push_back(4);
    vector<vector<int> > matrix;
    matrix.push_back(a1);
    matrix.push_back(a2);
    a1[0] = 7;
    a1[1] = 6;
    a1[2] = 5;
    matrix.push_back(a1);
    Solution s;
    s.spiralOrder(matrix);
}
