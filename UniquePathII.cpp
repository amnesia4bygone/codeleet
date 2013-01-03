class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (obstacleGrid.size() == 1)
        {
            if (obstacleGrid[0][0] != 1)
                return 1;
            else
                return 0;
        }
        
        
        vector<vector<int> > route;
        
        vector<int> one_line ;
        one_line.push_back(1);
        route.push_back(one_line);
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        for(int i=1; i<m+n; i++)
        {
             int x = 0;
             int y = i;
             if (y>=n)
             {
                 y = n-1;
                 x += i-y;
             }
             
             while(x >= m)
             {
                 
                 int left;
                 if (obstacleGrid[x][y-1] == 0 )
                    left = route[x][y-1];
                 else
                    left = 0;
                    
                 int top;
                 if (obstacleGrid[x][y-1] == 0) 
                    top = route[x-1][y];
                 else
                    top = 0;
                 
                 
                 
                 if (x==0)
                    route[x].push_back(left);
                 else if (y==0)
                    route[x].push_back(top);
                 else
                    route[x].push_back( top + left  ) ;
             }
        }
        return route[m-1][n-1];
        
    }
};
