class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0)
            return 0;
        
        if (n==1)
            return 1;
        
        int read_offset = 0;
        int write_offset = 0;
        
        int last = -999999;
        
        while(read_offset < n)
        {
            if ( A[read_offset] != last)
            {
                A[write_offset] = A[read_offset];
                last = A[read_offset];
                read_offset ++;
                write_offset ++;
            }
            else
            {
                read_offset ++;
            }
        }
        return write_offset;
        
    }
};
