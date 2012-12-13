class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0)
            return;
        
        int x=m-1; 
        int y=n-1;
        
        for (int i=n+m-1; i>= 0; i--)
        {
            if (x<0)
            {
                A[i] = B[y];
                y--;
                continue;
            }
            
            if (y<0)
            {
                A[i] = A[x];
                x--;
                continue;
            }
            
            if (A[x]>B[y])
            {
                A[i] =A[x]; 
                x--;
            }
            else
            {
                A[i] = B[y];
                y--;
            }
        }
        
        return;
    }
};
