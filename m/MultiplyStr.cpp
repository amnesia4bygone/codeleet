class Solution {
    public:

        long getlong(string num)
        {     
            long x = atol(num.c_str() );
            return x;
        }

        string getstr(long x)
        {
            string ss("0");
            if (x==0)
                return ss;

            vector<int> result;
            while(x>0)
            {
                int num = x%10;
                result.push_back(num);
                x = x/10;
            }

            string s;
            for(int i=result.size()-1; i>= 0; i--)
            {
                char buf[8];
                memset(buf, 0, 8);
                sprintf(buf, "%d", result[i]);
                string one(buf);
                s = s + one;
            }
            return s;
        }

        string multiply(string num1, string num2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int len1 = num1.length();
            int len2 = num2.length();

            int i = 0;
            long x1 = 0;
            while(len1>0)
            {
                x1 = x1 * 10000000000llu;

                int len ;
                if (len1> 5)
                {
                    len=5;
                    len1 -= 5;
                }
                else
                {
                    len = len1;
                    len1 = 0;
                }

                string one(num1, i, len );
                long x = getlong(one);
                x1 += x;
                i+=5;
            }

            i = 0;
            long x2 = 0;
            while(len2>0)
            {
                x2 = x2 * 100000llu;

                int len ;
                if (len2> 5)
                {
                    len=5;
                    len2 -= 5;
                }
                else
                {
                    len = len2;
                    len2 = 0;
                }

                string one(num2, i, len );
                long x = getlong(one);
                x2 += x;
                i+=5;
            }

            long result = x1 * x2;        

            return getstr(result);

        }
};
