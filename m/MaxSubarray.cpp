class Solution {
    public:
        int maxSubArray(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (n==1)
                return A[0];

            int max =A[0];
            int start = 0;


            for(int i=1; i<n; i++)
            {
                int sum = 0;
                for(int j=start; j<=i; j++)
                {
                    sum += A[j];
                }


                if (sum > A[i] && sum > max)
                {
                    max = sum;
                }
                else if (A[i] > max)
                {
                    start = i;
                    max = A[i];
                }
                else
                {
                    //
                }
            }
            return max;
        }
};
