#include <stdio.h>

class Solution {
    public:
        int sqrt(int x) {
            if (x==0)
                return 0;
            if (x<0)
                return 0;
            if (x==1)
                return 1;

            long value = 1;
            long number = 2;

            while (value< x  )
            {
                value = number*number;
                number *= 2; 
            }
            //printf("----%lld\n", number);
            if (value == x)
                return number;

            value = 1;
            long low = number/2;

            while( (number - low) > 2)
            {
                while( value < x )
                {
                    value = low * low;

                    low = (number + low)/2;
                }
                //printf("---%lld %lld\n", number, low);
                            if( (number-low) <2 )
                                            break;
                long tmp = low; // = (number + low)/2;
                number = low;
                low = (tmp/2 + number)/2;
                //low = number/2;
                value = 1;
            }
            return low;
        }
};

int main(void)
{
    Solution s;
    printf("%lld\n",s.sqrt(1));
    printf("%lld\n",s.sqrt(2));
    printf("%lld\n",s.sqrt(3));
    printf("%lld\n",s.sqrt(7));
    printf("%lld\n",s.sqrt(2147395599));
    printf("%lld\n",s.sqrt(2147395600));
    printf("%lld\n",s.sqrt(2147395601));
    return 1;
}

