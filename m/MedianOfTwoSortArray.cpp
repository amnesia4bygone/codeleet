class Solution {
    public:

        double ret_mid(int B[], int n)
        {
            if (n==0)
                return 0;

            if (n%2 == 0)
            {
                double x = B[(n-1)/2];
                double y = B[(n+1)/2];
                double r = double((x+y)/2);
                return r;
            }
            else
            {
                return double(B[n/2]);
            }        
        }




        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            if (m==0)
            {
                return ret_mid(B, n);
            }

            if (n==0)
            {
                return ret_mid(A, m);
            }


            if (m+n == 2)
            {
                double x = A[0];
                double y = B[0];
                return (x+y)/2;
            }

            // a_mid, b_mid is virtual number
            double a_mid = ret_mid(A, m);
            double b_mid = ret_mid(B, n);

            if (a_mid == b_mid)
            {
                return a_mid;
            }
            else if (a_mid > b_mid)
            {
                return findMedianSortedArrays(A, (m+1)/2, B+(n+1)/2, (n+1)/2 );

            }
            else
            {
                return findMedianSortedArrays(A+m/2, (m+1)/2, B, (n+1)/2 );
            }


        }
};
