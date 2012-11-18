class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        unsigned int len1 = a.length();
        unsigned int len2 = b.length();
        
        if (len1 == 0)
            return b;
        if (len2 == 0)
            return a;
        
        string result;
        
        int i = len1-1;
        int j = len2 -1;
        
        int m = 0;
        
        int c_a = 0;
        int c_b = 0;
        
        char buffer1[8];
        char buffer2[8];
        
        
        while( i>=0 || j>=0 )
        {
            if (i<0) 
                c_a = 0;
            else 
            {
                a.copy(buffer1, 1, i);
                buffer1[1] = '\0';
                if ( atoi(buffer1) == 0  )
                    c_a = 0;
                else
                    c_a = 1;
            }
            
            if (j<0)
                c_b = 0;
            else 
            {
                b.copy(buffer2, 1, j);
                buffer2[1] = '\0';
                if (atoi(buffer2) == 0 )
                    c_b = 0;
                else
                    c_b = 1;
            }
            
            int x  = m + c_a + c_b;
            if (x==0)
            {
                result.insert(0, "0");
                m = 0 ;
            }
            else if (x==1)
            {
                result.insert(0, "1");
                m = 0;
            }
            else if (x==2)
            {
                result.insert(0, "0");
                m =1;
            }
            else
            {
                result.insert(0, "1");
                m = 1;
            }
            i--;
            j--;
        }
        if (m==1)
            result.insert(0, "1");
        return result;
    }
};
