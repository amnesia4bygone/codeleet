class Solution {
public:

    
    
    // £¬¼´I(1)£¬V(5)£¬X(10)£¬L(50)£¬C(100)£¬D(500)£¬M(1000)¡£
    int return_val(char c)
    {
        if (c == 'I')
            return 1;
            
        if (c == 'V')
            return 5;
            
        if (c == 'X')
            return 10;
            
        if (c == 'L')
            return 50;
            
        if (c =='C')
            return 100;
            
        if (c == 'D')
            return 500;
        else
            return 1000;
    }
    
    int is_sub(char c1 , char c2)
    {
        int x1 = return_val(c1);
        int x2 = return_val(c2);
        
        if (x1< x2)
            return 1;
        else
            return 0;
    }

    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int val = 0;
        
        int flag = 1;
        
        for(int i = s.length() -1; i>=0; i--)
        {
            int tmp = return_val(s[i]);
            
            if (i == s.length() -1)
                flag = 0;
            else
                flag = is_sub(s[i], s[i+1]);
            
            if (flag == 1)
                val -= tmp;
            else
                val += tmp;
        }
        return val;
        
        
        return 1;
    }
};
