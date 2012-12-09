class Solution {
    public:

        int  findK(int A[], int m, int B[], int n, int k) 
        {
            int x1 = A[m/2];
            int x2 = B[n/2];
            int len1 = (m+1)/2;
            int len2 = (n+1)/2;
            int len1_top = (m+1)/2;
            int len2_top  = (n+1)/2;


            if (m==0)
            {
                len1 = 0;
                len1_top = 0;    
            }

            if (n==0)
            {
                len2 = 0;
                len2_top = 0;
            }


            int result = -1;


            if (len1 + len2 > k) //
            {
                return findK(A+ len1_top, len1, B+len2_top, len2, k);
            }
            else if (len1 + len2 == k)
            {
                int tmp1 = A[len1-1];
                int tmp2 = B[len2-1];

                if (tmp1>tmp2)
                    return tmp2;
                else
                    return tmp1;
            }
            else // len1 + len2 < k
            {
                return findK(A, len1_top, B, len2_top, k-(len1+len2));
            }



        }

        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() functio
            if (m==0 && n==0)
                return 0;

            if (m==0)
            {
                if(n==1)
                    return B[0];

                if (n%2==0)
                {
                    double x = B[(n-1)/2];
                    x += B[(n+1)/2];
                    return x/2;
                }
                else
                {
                    return B[n/2];
                }
            }

            if (n==0)
            {
                if (m==1)
                    return A[0];
                if (m%2==0)
                {
                    double x = A[(m-1)/2];
                    x += A[(m+1)/2];
                    return x/2;
                }
                else
                {
                    return A[m/2];
                }
            }

            if (m==1 && n==1)
                return (A[0]+B[0] )/2;


            if ((m+n)%2 == 0 )
            {
                int k1 = (n+m+1)/2;
                int k2 = (n+m-1)/2;

                int x1 = findK(A, n, B, m, k1);
                int x2 = findK(A, n, B, m, k2);
                double result = (x1+x2)/2;
                return result;
            }
            else
            {
                int k = (n+m)/2;
                int x = findK(A, n, B, m, k);
                return x;
            }



            return 0;
        }
};
