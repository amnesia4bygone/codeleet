#include <stdio.h>

class Solution {
public:

    int subdivide(unsigned int dividend, unsigned int divisor)
    {
        printf("-%d--%d-\n", dividend, divisor); 
        if (dividend < divisor)
            return 0;
        
        if (dividend == divisor)
            return 1;
            
        
        int result = 1;
        
        int subdivisor= divisor;
        
        
        while(subdivisor<<1  <  dividend)
        {
            subdivisor = subdivisor<<1;
            result = result<<1;
            printf("!!!-%d--%d-\n", result, subdivisor); 
        }
        
        return result + subdivide( dividend-subdivisor, divisor );
        
        
    }

    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (divisor==0)
            return 0;
        
        int flag = 1;
        if (dividend < 0)
        {
            dividend *= -1;
            flag *= -1;
        }
        
        if (divisor < 0)
        {
            divisor *= -1;
            flag *= -1;            
        }
        
        if(dividend < divisor)
            return 0;
        if (divisor == 1)
            return flag*dividend;
        
        return flag * subdivide(dividend, divisor);
        
    }
};


int main(void)
{
	int x = 2147483647;
	int y = 2;
	Solution s;
	printf("%d\n", s.subdivide(x, y)  );
}
