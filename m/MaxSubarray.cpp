class Solution {
    public:


        int maxSubArray(int A[], int n) {
            // divide and conquer
            //return 1;
            if (n==0)
                return 0;
            if (n==1)
                return A[0];

            //return 1;


            int max = -99999;
            int last_max = -99999;

            for(int i=0; i<n; i++)
            {
                if (A[i] > A[i]+ last_max)
                {
                    last_max = A[i];
                }
                else
                {
                    last_max += A[i];
                }

                if (max < last_max)
                    max = last_max;
            }


            return max;

        }
};
