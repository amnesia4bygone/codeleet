#include <stdio.h>

class Solution {

    
public:
    void dump(int A[], int n)
    {
	for(int i=0;i<n;i++)
		printf("%d ", A[i]);
 	printf("\n");	
    }
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n<=1 )
            return;
        
        if (n<=2)
        {
            if (A[0]>A[1])
            {
                int tmp = A[0];
                A[0] = A[1];
                A[1] = tmp;
            }
            return;
        }
        
        int tail_offset = n-1;
        int zero_offset = 0;
        int one_offset = n-1;
        
        while( zero_offset<=one_offset && zero_offset <= tail_offset && one_offset <= tail_offset )
        {
            while(A[zero_offset] == 0 && zero_offset<n)
            {
                zero_offset++;
            }
            
            while(A[one_offset] == 1 && one_offset>=0)
            {
                one_offset--;
            }
            
            while(A[tail_offset] == 2 && tail_offset>=0)
            {
                tail_offset--;
            }
            
            if (zero_offset>one_offset && zero_offset>tail_offset && one_offset>tail_offset)
                break;
            dump(A,n);
	    printf("%d %d %d\n", zero_offset, one_offset, tail_offset); 
            if (A[zero_offset]==2)
            {
                int tmp = A[zero_offset];
                A[zero_offset] = A[tail_offset];
                A[tail_offset] = tmp;
            }
            else if (A[one_offset] == 2)
            {
                int tmp = A[one_offset];
                A[one_offset] = A[tail_offset];
                A[tail_offset] = tmp;                
            }
            else
            {
                int tmp = A[zero_offset];
                A[zero_offset] = A[one_offset];
                A[one_offset] = tmp;
            }
            dump(A,n);
        }
        
        return;
    }
};

int main(void)
{
        int A[3];
        A[0] = 0;
        A[1] = 2;
        A[2] = 1;
        Solution s;
        s.sortColors(A,3);
        return 0;
}
