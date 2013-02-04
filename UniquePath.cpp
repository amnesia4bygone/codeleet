#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // bug here
        if (n==1 || m==1)
            return 1;
            
        vector< vector<int> > M = vector< vector<int> >(m+1, vector<int>(n+1, 0) );
        
	// bug here
        M[1][0] = 1;
        
        int start_row = 1;
        int start_col = 1;
        
        while(  !( start_row == m && start_col == n) )
        {
            int sum = start_row + start_col;
            
            for( int i=start_row; i>=1; i-- )
            {
                M[i][sum-i] = M[i-1][sum-i]  + M[i][sum-i-1];
	        printf("\t\t%d %d\n", i, sum-i);
            }
            
            if (start_row != m)
                start_row++;
            else
                start_col++;
	    printf("%d %d\n", start_row, start_col);
        }
	// bug here
        return M[m-1][n] + M[m][n-1];
    }
};

int main(void)
{
	Solution s;
	printf("-%d-\n", s.uniquePaths(10,10) );
	return 1;
}
