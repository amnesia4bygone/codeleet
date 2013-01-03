class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // DO NOT write int main() function
        if (obstacleGrid.size() == 1)
        {
            if (obstacleGrid[0][0] != 1)
                return 1;
            else
                return 0;
        }
        int m = obstacleGrid.size() +1;
        int n = obstacleGrid[0].size() +1;
                
        
        vector<vector<int> > route;
        
        vector<int> one_line ;
        for(int i=0; i<m;i++)
        {
            route.push_back(one_line);
            route[i].push_back(1);
        }
        for (int i=0; i<n; i++)
            route[0][i] = 1;
        
          
        for(int i=1; i<=m ; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==1 && j==1)
                {
                    route[1][1] = 1;
                    continue;
                }
                
                int left; 
                int top;
                
                if ( obstacleGrid[i-1][j] ==1 )
                    top = 0;
                else
                    top = route[i-1][j];
                    
                if (j==0|| obstacleGrid[i][j-1] ==1 )
                    left = 0;
                else
                    left = route[i][j-1];
                
                route[i][j] = top + left;
            }
        }
        return route[m-1][n-1];
        
/*
        for(int i=1; i<m+n; i++)
        {
             int x = 0;
             int y = i;

             
             while(x < m)
             {
                 if (y>=n)
                 {
                     y = n-1;
                     x = i-y;
                 }
                 if (x>=m)
                 {
                     x =m-1;
                     y = i - x;
                 }
             
             
                 int left;
                 if (obstacleGrid[x][y-1] == 0 )
                    left = route[x][y-1];
                 else
                    left = 0;
                    
                 int top;
                 if (obstacleGrid[x-1][y] == 0) 
                    top = route[x-1][y];
                 else
                    top = 0;
                 
                 
                 
                 if (x==0)
                    route[x].push_back(left);
                 else if (y==0)
                    route[x].push_back(top);
                 else
                    route[x].push_back( top + left  ) ;
                
                 x++;
             }
        }*/
        
        
        
        
    }
};
