class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if (len <= 1)
            return len;
        
        vector<int> S = vector<int> ( 26 , 0);
        
        int max = -1;
        int tmp_max = 0;
        //i offset
        for(int i=0; i<len; i++)
        {
            if (S[  s[i] - 'a' ] == 0)
            {
                tmp_max++;
                
                if (tmp_max > max)
                    max = tmp_max;
                
            }
            else
            {
                int start_offset = S[s[i]-'a' ];
                
                int new_len  = i - start_offset +1 ;
                
                //               bug here
                if (new_len > tmp_max )
                {
                    
                    tmp_max ++;
                    continue; // bug
                    //max = new_len;
                    //tmp_max = new_len;
                }
                else
                {
                    tmp_max = new_len;
                }
    
            }
            S[ s[i] - 'a'] = i+1;
        }
        return max; 
    }
};
