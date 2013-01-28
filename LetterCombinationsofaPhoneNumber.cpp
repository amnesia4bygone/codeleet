class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        vector<string> keys;
        keys.push_back(string(""));
        keys.push_back(string(""));
        keys.push_back(string("abc"));
        keys.push_back(string("def"));
        keys.push_back(string("ghi"));
        keys.push_back(string("jkl"));
        keys.push_back(string("mno"));
        keys.push_back(string("qprs"));
        keys.push_back(string("tuv"));
        keys.push_back(string("wxyz"));
        
        
        int len = digits.length();

            
        for(int i=0; i<len; i++)
        {
            //string one(1, digits[i]);
            string one = keys[ int(digits[i] - '0') ];
            
            int num = one.length();
            
            if (num == 0)
                continue;
            
            if (result.size() == 0)
            {
                for(int j=0; j<num; j++)
                {
                    string tmp(1, one[j]);
                    result.push_back(tmp);
                }
            }
            else
            {
                int cur_len = result.size();
                for(int j=1; j<num; j++)
                {
                    for(int k=0; k<cur_len; k++)
                    {
                        result.push_back( result[k] ); 
                    }
                }
                
                for(int j=0; j<num; j++)
                {
                    for(int k=0; k<cur_len; k++)
                    {
                        string tmp(1, one[j]);
                        result[j*cur_len + k] += tmp;
                    }                    
                }
                
            }
        }
        
        if (result.size() == 0)
            result.push_back(string(""));
        return result;
        
    }
};
