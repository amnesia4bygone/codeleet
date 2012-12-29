class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len1 = s1.length();
        int len2 = s2.length();
        
        if (len1==0 && len2 == 0)
            return true;
        
        if (len1==0 || len2 == 0 || len1 != len2)
            return false;
        
        if (len1==1 )
        {
            if( s1 == s2)
                return true;
            else
                return false;
        }
        
        if (len1 ==2 )
        {
            string s1_left;   s1_left.assign(s1, 0, 1);
            string s1_right;  s1_right.assign(s1, 1, 1);
            string s2_left;   s2_left.assign(s2, 0, 1);
            string s2_right;  s2_right.assign(s2, 1, 1);
            
            if (s1_left == s2_left && s1_right==s2_right)
                return true;
            else if (s1_left == s2_right && s1_right == s2_left)
                return true;
            else
                return false;
        }
        
        bool flag = false;
        for(int i=1; i<len1; i++)
        {
            string s1_left;   s1_left.assign(s1, 0, i);
            string s1_right;  s1_right.assign(s1, i, len1-i);
            string s2_left;   s2_left.assign(s2, 0, i);
            string s2_right;  s2_right.assign(s2, i, len1-i);
            
            string s22_left; s22_left.assign(s2,  len1-i ,i);
            string s22_right; s22_right.assign(s2, 0, len1 - i);
            
            if ( isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right) )
            {
                flag = true;
                break;
            }
            if ( isScramble(s1_left, s22_left) && isScramble(s1_right, s22_right) )
            {
                flag = true;
                break;
            }            
            
                
        }
        return flag;
    }
};
