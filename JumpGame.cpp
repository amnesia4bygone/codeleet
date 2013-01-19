class Solution {
public:

    bool inner_jump(int A[], int offset, int n)
    {
        if (n==0)
            return true;
        
        if(offset >= n)
            return false;
        
        if (offset == n-1)
            return true;
        
        
        if (A[offset] == 0)
            return false;
        
        for(int i=A[offset]; i>=1; i--)
        {
            if ( inner_jump(A, offset+i, n) == true )
                return true;
        }
        return false;
    }

    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return inner_jump(A, 0, n);      
    }
};
