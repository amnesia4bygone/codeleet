#include <stdio.h>

class Solution {
    public:
        void sortColors(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int *p_end = A+n -1;
            int *p_start = A;

            int *p_0 = A;
            int *p_2 = A;



            while (p_end > p_start )
            {
                while (p_0 - A < n  && *p_0 != 0  )
                {
                    p_0++;
                }
                    printf("1 %d\n", p_0 - A);

                while(p_2 - A < n && *p_2 != 2) 
                {
                    p_2 ++;
                }
                    printf("2 %d\n", p_2 - A);

                int tmp;

                if (p_0 - A != n && p_end > p_start)
                {
                    printf("11 %d\n", p_0 - A);
                    tmp = *p_start;
                    *p_start = *p_0;
                    *p_0 = tmp;
                    p_start++;

                }

                if (p_2 - A != n && p_end > p_start )
                {
                    printf("22 %d\n", p_2 - A);
                    tmp = *p_end;
                    *p_end = *p_2;
                    *p_2 = tmp;
                    p_end--;
                }

                if (p_0 == A+n && p_2 == A+n)
                    break;
            }

        }
};

int main(void)
{
        int A[2];
        A[0] = 2;
        A[1] = 0;
        Solution s;
        s.sortColors(A,2);
        return 0;
}
