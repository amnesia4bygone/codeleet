class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        
        if (len == 0)
            return true;
        
        
        string new_string;
        int offset = 'a' - 'A';
        
        for(int i=0; i<len; i++)
        {
            char c = s[i];
            if ( c >= 'a' && c<='z')
                new_string.append(1, c);
            else if (( c >= 'A' && c<='Z'))
            {
                char new_c = c + offset;
                new_string.append(1, new_c);
            }
            // bug here
            else if ( c >= '0' && c<='9')
                new_string.append(1, c);
            else
            {
                // do nothing
            }
        }
        
        len = new_string.length();
        if (len == 0)
            return true;
        
        int i=0; 
        int j = len-1;
        
        while(i<j)
        {
            if (new_string[i] != new_string[j])
                return false;
            i++;
            j--;
                
        }
        
        return true;
    }
};
