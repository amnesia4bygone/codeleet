class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if (m<1)
            return 0;
        
        int n = obstacleGrid[0].size();
        if (n<1)
            return 0;
        
        
        int * route = (int *) malloc( n*m*sizeof(int) );
        if (obstacleGrid[0][0] == 0)
            route[0] = 1;
        else
            return 0;
        
        // deal with line0, except j=0
        int flag = 0;
        for(int j=1; j<n; j++)
        {
            if(flag == 1 || obstacleGrid[0][j] == 1)
            {
                route[j] = 0;
                //obstacleGrid[0][j] = 1;   
                flag = 1;
            }
            else
                route[j] = 1;
        }
        
        // deal with col0, except i=0
        flag = 0;
        for(int i=1; i<m; i++)
        {
            if(flag == 1 || obstacleGrid[i][0] == 1)
            {
                route[i*n] = 0;
                //obstacleGrid[i][0] = 1;   
                flag = 1;
            }
            else
                route[i*n] = 1;            
        }
        
        for(int i=1; i<m; i++)
        {
            for (int j=1; j<n; j++)
            {
                int top = route[ (i-1)*n + j];
                int left = route[i*n + j-1];
                
                if (obstacleGrid[i][j] == 1)
                {
                    route[i*n + j] = 0;
                }
                else
                {
                    route[i*n + j] = top + left;
                }
            }
        }
        int ret = route[ (m-1)*n  + n-1];
        free(route ); route = NULL;
        return ret;
        
    }
};
