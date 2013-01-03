class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        
        string tail;
        string tmp;
        char * p = (char*)s;
        while( *p != '\0')
        {
            if (*p == ' ')
            {
                if (tmp.length() > 0)
                {
                    tail = tmp;
                }
                tmp.clear();
                
            }
            else
            {
                string one(p, 1);
                tmp += one;
            }
            p++;
        }
        
        
        if (tmp.length() > 0)
            tail = tmp;
        
        return tail.length();
    }
};
