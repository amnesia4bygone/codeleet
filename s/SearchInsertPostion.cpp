class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int * p = A;

            for (int i=0; i<n; i++)
            {
                int tmp = *p;

                if (tmp == target)
                    return i;

                if (tmp > target)
                    return i;

                p++;



            }
            return n;
        }
};
