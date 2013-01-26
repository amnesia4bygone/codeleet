class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<=0)
            return 0;
        
        if (n==1)
            return 1;
        
        if (n==2)
            return 2;
        
        int x1 = 1;
        int x2 = 2;
        int tmp = 0;
        
        for(int i=3; i<=n; i++)
        {
            tmp = x1 + x2;
           
            x1 = x2;
             x2 = tmp;
        }
        
        return tmp;
        
    }
};
