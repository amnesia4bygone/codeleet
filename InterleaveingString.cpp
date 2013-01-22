class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        // bug
        if (len1 + len2 != len3)
            return false;

        vector< vector<int> > M = vector< vector<int> >(len1+1, vector<int>(len2+1, 0) );
        
        if (len1 == 0 && len2 == 0)
        {
            if (len3 == 0) return true;
            else    return false;
        }
        
        if (len1 == 0 )
        {
            if (s3 == s2) return true;
            else return false;
        }
        
        if (len2 == 0)
        {
            if (s1 == s3) return true;
            else return false;
        }
        
        for(int i=1; i<=len1; i++)
        {
            string s(s1, 0 , i );
            string sub_s3 (s3, 0, i);
            
            if (s == sub_s3)
                M[i][0] = 1;
        }
        
        for(int i=1; i<=len2; i++)
        {
            string s(s2, 0 , i );
            string sub_s3 (s3, 0, i);
            
            if (s == sub_s3)
                M[0][i] = 1;
        }
            
        
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                // bug, s index error
                if ( s3[i+j-1] == s2[j-1] && M[i][j-1] == 1)
                    M[i][j] = 1;
                
                // missing this logic
                if (s3[i+j-1] == s1[i-1] && M[i-1][j] == 1)
                    M[i][j] = 1;
            
            }
        }
        
        if( M[len1][len2] == 1) return true;
        else return false;
        
        
    }
};

/*

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
}; */
