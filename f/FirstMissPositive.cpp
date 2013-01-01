class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0)
            return 1;
        
        int first_positive  = -1;
        for(int i=0;i<n; i++)
        {
            if( A[i] > 0)
            {
                first_positive = A[i];
                break;
            }
        }
        if( first_positive == -1)
            return 1;
        
        
        for(int i=0; i<n; i++)
        {
            if (A[i] <= 0 )
                A[i] = first_positive;
        }
        
        for(int i=0; i<n; i++)
        {
            int tmp = abs(A[i]);
            
            if (tmp > n )
                continue;
            
            int offset = tmp - 1;
            
            int offset_val = abs(A[offset]);
            A[offset] = offset_val * -1;      
        }
        
        for(int i=0; i<n; i++)
        {
            if (A[i] > 0)
                return (i+1);
        }
        return (n+1);
    }
};
