class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int new_len = 0;
        
        if (n==0)
            return 0;
        
        int read_offset = 0;
        int write_offset = 0;
        
        while(read_offset < n)
        {
            if (A[read_offset] == elem)
            {
                
            }
            else
            {
                A[write_offset] = A[read_offset];
                write_offset++;
                new_len++;
            }
            
            read_offset++;
        }
        
        return new_len;
        
        
    }
};
