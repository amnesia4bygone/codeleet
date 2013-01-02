#include "stdio.h"

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int max = -1;
        for(int i=0; i<n; i++)
        {
            if (A[i] > max )
            {
                max = A[i];
            }
        }
        
        if (max == -1)
            return 0;
            
        int total = max * n;
	for(int i=0 ; i<n; i++)
		total -= A[i];

	printf("total %d\n", total);        
        int bar = A[0];
        for(int i=0; i<n; i++)
        {
            if (A[i] > bar)
            {
                int pre_bar = bar;
                bar = A[i];
                
                total -= (bar - pre_bar) * (i);
		printf("total %d\n", total);        
            }
        }

        bar = A[n-1];
        for(int i=n-1; i>=0; i--)
        {
            if (A[i] > bar)
            {
                int pre_bar = bar;
                bar = A[i];
                
                total -= (bar - pre_bar) * (n-i-1);
		printf("total %d\n", total);        
            }            
        }
        
        
        return total;
    }
};

int main(void)
{
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution s;
	int result = s.trap(A, 12);
	printf("%d\n", result);
	return 1;
}
