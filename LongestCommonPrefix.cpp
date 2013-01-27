class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
              
        if (strs.size() == 0)
            return result;
        
        if (strs.size() == 1)
            return strs[0];
        
        int len = 1;
        //           =, is bug
        while ( len <= strs[0].length())
        {
            for(int j=0; j<strs.size(); j++)
                if ( strs[j].length() < len )
                    return result;
            
            char c = strs[0][len-1];
            
            for(int j=0; j<strs.size(); j++)
                if ( strs[j][len-1] != c )
                    return result;            
            
            result += strs[0][len-1];
            // bug
            len++;
        }
        
        return result;
    }
};
