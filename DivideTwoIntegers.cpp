#include <stdio.h>

class Solution {
public:
	//	    bug here
    int subdivide(unsigned int dividend, unsigned int divisor)
    {
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

            // here should nice
            if (subdivisor == dividend )
                return result;
        }
        
        return result + subdivide( dividend-subdivisor, divisor );
        
    }

    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (divisor==0)
            return 0;
        
        int flag = 1;
	// bug here
        unsigned int x = dividend;
        unsigned int y = divisor;
        
        if (dividend < 0)
        {
            x = -dividend;
            flag *= -1;
        }
        
        if (divisor < 0)
        {
            y = -divisor;
            flag *= -1;            
        }
        
        if(x < y)
            return 0;
        if (y == 1)
            return flag*x;
        
        return flag * subdivide(x, y);
        
    }
};


int main(void)
{
	int x = -2147483648;
	int y = 2;
	Solution s;
	printf("%d\n", s.subdivide(x, y)  );
}
