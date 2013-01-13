class Solution {
public:

    

    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
        if (s3.length() == 0 && s1.length() == 0 && s2.length() == 0)
            return true;
        
        if (s1.length() == 0)
        {
            if (s2 == s3)
                return true;
            else
                return false;
        }
        
        if (s2.length() == 0)
        {
            if (s1 == s3)
                return true;
            else
                return false;
        }
        
        if (s3.length() == 0 && (s1.length()>0 || s2.length() > 0) )
            return false;
        
        if (s3.length()  != s1.length() + s2.length() )
            return false;
        
        char c = s3[0];
        
        bool result1 = false;
        bool result2 = false;
        
        if (s1.length() > 0 && c == s1[0] )
        {
             string new_s1(s1, 1);
             //new_s1.assign(s1, 1);
             
             string new_s3(s3, 1);
             //new_s3.assign;
             result1 = isInterleave(new_s1 , s2, new_s3 );
             
             if (result1 == true)
                return true;
        }
        
        if (s2.length() > 0 && c == s2[0] )
        {
            string new_s2(s2, 1);
            //new_s2.assign;
            
            string new_s3(s3, 1);
            //new_s3.assign;
            
            result2 = isInterleave(s1, new_s2, new_s3);
            if (result2 == true)
                return true;
        }
        return false;
        
    }
};
