class Solution {
public:

    int inner_jump(int A[], int offset , int n)
    {
        if (offset == n-1)
            return 0;
        
        // bug here, n-1
        if (offset + A[offset] >= n-1)
            return 1;
        
        if ( A[offset] == 0 )
            return 999999;
        
        int min = 999;
        for(int i=A[offset]; i>=1; i--)
        {
            int ret = inner_jump(A, offset+i, n);
            if (ret<min)
                min = ret;
        }
        
        // bug here +1
        return min+1;
    } 

    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return inner_jump(A, 0, n);
        
        
    }
};
