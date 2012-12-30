class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin =0;
        int end = n-1;
        
        if (n==0)
            return 0;
        
        if (n==1)
        {
            if (target > A[0])
                return 1;
            else
                return 0;
        }
        
        while(begin  < end )
        {
            int mid = (begin + end + 1 ) /2;
            
            if (target == A[mid])
                return mid;
            
            if (begin +1 == end)
            {
                if (target > A[end])
                    return end+1;
                else if (target < A[begin] )
                    return begin;
                else if (target == A[begin])
                    return begin;
                else
                    return end;
            }
            
            if (target > A[mid])
                begin  = mid;
            else
                end = mid;
        }
        return begin;
        
    }
};
