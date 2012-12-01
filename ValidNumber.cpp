#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Solution {
    public:

        int is_state(const char * buf, int len)
        {
            char c = buf[0];
            if( 0 == strncmp("log", buf, len ) || 0 == strncmp("l", buf, 1 ))
            {
                return 2;
            }
            if (c == 'e')
            {
                return 1;
            }
            if (c == '.' )
            {
                return 3;
            }
            if (c == '+')
                return 4;
            if (c == '-' )
                return 5;
            if (c>= '0' && c <= '9')
                return 6;
            if (c == ' ')
                return 7;
            else
                return -1;
        }

        bool isNumber(const char *s) {
            // 0 ,number
            // 1, e
            // 2, log
            // 3, .
            // 4, +
            // 5, -
            // 6, number
            // 7, blank

            int mix = 0;

            if (s==NULL)
                return false;

            int state;

            int len = strlen(s);
            if (len ==0) return false;

            bool ret = false;

            int i =0;

            int dot = 0;
            int e = 0;
            int plus = 0;
            int sub = 0;
            int blank = 0;
            int num = 0;

            while(i<len)
            {
                state = is_state(s+i, 1);

                //if (mix >1)
                //   return false;

                if (state == -1)
                    return false;

                else if (state == 6)
                {
                    ret = true;

                    if (i+1 != len)
                    {
                        if( is_state(s+i+1 , 1) == 7 )
                            num++;
                    }

                    if (i-1 != 0)
                    {
                        if( is_state(s+i-1 , 1) == 7 )
                            num++;                    
                    }

                    i++;
                }
                else if (state == 4|| state == 5)
                {
                    if (i == len-1)
                        return false;
                    if (is_state(s+i+1, 1) != 6 && is_state(s+i+1, 1) != 3  )
                        return false;
                    if (i != 0)
                    {
                        if (is_state(s+i-1, 1) == 6)
                            return false;
                    }
                    i++;
                    sub ++;
                }
                else if ( state == 3)
                {
                    //if (i==0 )//|| i == len-1)
                    //  return false;
                    if (i!=0 && is_state(s+i-1, 1) != 6) // || is_state(s+i+1, 1) != 6 ) 
                        return false;
                    i++;
                    dot ++;
                }
                else if (state == 1 )
                {
                    if (i==0 || i == len-1)
                        return false;

                    int x = is_state(s+i-1, 1) ;
                    int y = is_state(s+i+1, 1);
                    if ( x != 6 &&  y!= 6  &&  y!= 4 && y != 5 && x!= 4 && x!= 5) 
                        return false;
                    i++;
                    e++;
                }
                else if (state == 2 )
                {
                    if ( 2 != is_state(s+i, 3) )
                        return false;
                    if (6 != is_state(s+i+3, 1))
                        return false;
                    i+=3;
                    mix++;
                }
                else // if (state ==7)
                {
                    i++;
                    blank++;
                }

                if (dot >1)
                    return false;
                if (e >1)
                    return false;
                if (num >2)
                    return false;
                if (sub >1)
                    return false;                
            }
            return ret;
        }
};

int main(void)
{
    char buf[]= "2e10";;
    Solution s;
    bool ret = s.isNumber(buf);
    if (ret == false)
    {
        printf("false\n");
    }
    else
    {
    }
}
