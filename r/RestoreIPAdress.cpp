class Solution {
    public:


        string  find_one_segment(string s)
        {

            string result;
            int len = s.length();
            if (len == 0)
                return result;

            int x = atoi(s.c_str());

            char buf[32];
            memset(buf, 0, 32);
            sprintf(buf, "%d", x);

            if (x < 0 || x >255 ||  strlen(buf)!= len )
            {
                string result;
                return result;
            }
            else
            {
                return s;
            }

        }

        vector<string> find_two_segment(string s)
        {
            vector<string> result;
            int len = s.length();

            if (len <2)
                return result;


            for (int i=1; i<len; i++)
            {
                string one(s, 0, i);
                string two ( s, i,  len-i);

                string x1 = find_one_segment(one);
                string x2 = find_one_segment(two);

                if( x1.length() != 0 && x2.length() != 0)
                {
                    result.push_back(x1 + "." + x2);
                }
            }
            return result;

        }

        vector<string> restoreIpAddresses(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<string> result;

            int len = s.length();

            if( len<=3 || len > 12)
                return result;

            for(int i=2; i<len-1; i++)
            {
                string one(s,  0, i);
                string two(s, i, len  -i);

                vector<string> result1 = find_two_segment(one);
                vector<string> result2 = find_two_segment(two);

                if (result1.size() != 0 && result2.size() != 0)
                {
                    for (int n=0; n<result1.size(); n++)
                    {
                        for(int m=0; m<result2.size(); m++)
                        {
                            string tmp = result1[n] + "." + result2[m];
                            result.push_back(tmp);
                        }
                    }

                }
            }


            return result;
        }
};
