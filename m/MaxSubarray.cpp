#include <vector>
#include "stdio.h"
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maxSubArray(int A[], int n) {
            // divide and conquer

            if (n==1)
                return A[0];

            int left = maxSubArray(A, n/2  );
            int right = maxSubArray(A+n/2, (n+1)/2);

            int i=(n-1)/2;
            int j=(n+1)/2;

            int maxi = -9999;
            int maxj = -9999;

            vector<int> result;
            int sum = 0;
            while(i>=0)
            {
                sum += A[i];
                result.push_back(sum);
                i--;
            }
            for(int x=0; x<result.size(); x++)
            {
                if ( maxi < result[x] )
                    maxi = result[x];
            }

            sum = 0;
            result.clear();
            while(j<=n-1)
            {
                sum += A[j];
                result.push_back(sum);
                j++;
            }
            for(int x=0; x<result.size(); x++)
            {
                if ( maxj < result[x] )
                    maxj = result[x];
            }  
            int max  = maxj + maxi;

            result.clear();
            result.push_back(max);
            result.push_back(maxj);
            result.push_back(maxi);
            result.push_back(left);
            result.push_back(right);
            sort(result.begin(), result.end());
            return result[4];

        }
};


int main(void)
{
        //[1,2,-1,-2,2,1,-2,1,4,-5,4]
        //int A[11] = {1,2,-1,-2,2,1,-2,1,4,-5,4,};
        int A[] = {-9,9,7,-8,-3,2,-9,1,7,-2,-9,7,-9,5,5,-3,9,0};
        Solution s;
        int x = s.maxSubArray(A, 18);
        printf("%d\n", x);
        return 0;
}
