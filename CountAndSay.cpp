class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n==0)
        {
            string s;
            return s;
        }
        
        if (n==1)
        {
            string s("1");
            return s;
        }
        
        string s = countAndSay(n-1);
        string result;
        
        string tmp;
        int len = 0;
        for(unsigned int i=0; i<s.length(); i++)
        {
            // bug
            if (i == 0)
            {
                tmp.assign(s, i, 1);
                len++;
            }
            else
            {
                if (s[i] == tmp[0])
                {
                    len++;
                }
                else
                {
                    char buf[8];
                    memset(buf, 0, 8);
                    sprintf(buf, "%d", len);
                    result += string(buf);
                    result += tmp;
                    
                    // bug
                    tmp[0] = s[i];
                    len = 1;
                }
            }
        }
        
        if (tmp.length() > 0 )
        {
            char buf[8];
            memset(buf, 0, 8);
            sprintf(buf, "%d", len);
            result += string(buf);
            result += tmp;          
        }
        
        return result;
    }
};
