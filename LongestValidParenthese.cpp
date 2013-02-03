class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        
        if (len <=1)
            return 0;
        
        int max  = 0;
        
        vector<int> M = vector<int>(len+1, 0);
        M[0] = 0;
        
        for(int i=0; i<len; i++)
        {
            int pre_offset = i -  M[i-1] - 1;
            
            if ( pre_offset < 0 )
            {
                M[i] = 0 ;
            }
            else
            {
                char pre = s[ pre_offset ];
                
                if ( s[i] == ')' && pre == '(' )
                {
                    if (pre_offset > 0)
                        M[i] =  M[pre_offset-1] + M[i-1] + 2;
                    else
                        M[i] = M[i-1] + 2;
                }
                else
                {
                    M[i] = 0;
                }
            }
        }
        
        sort(M.begin(), M.end());
        return M[ M.size() -1];
        

    }
};
