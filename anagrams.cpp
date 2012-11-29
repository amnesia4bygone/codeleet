class Solution {
public:

    unsigned long build_md5(string &s)
    {
        unsigned int len = s.length();
        unsigned long result = 0;
        for (int i =0; i<len; i++)
        {
            char c = s[i];
            
            int x = int(c);
            
            result += 1<<x;
        }
        return result;
    }
    

    struct myclass {
        bool operator() (string &i,string &j) 
        { 
            unsigned long code_a = build_md5( i );
            unsigned long code_b = build_md5( j );
            
            if (code_a >= code_b )
                return false;
            else
                return true;
        }
    } myobject;

    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unsigned int len = strs.size();
        vector<unsigned long> result_code;
        
        sort(strs.begin(), strs.end(), myobject);
        
        vector<string> result;
        
        for (int i =0; i<len; i++)
        {
            unsigned long one = build_md5(strs[i]);
            result_code.push_back(one);
        }
        
        int current_value=-1;
        int current_position = 0;
        for (int i=1; i<len ; i++)
        {
            if (i==len-1  && i>1 && result_code[i] == result_code[i-1])
            {
                result.push_back(strs[i]);
                break;
            }
             
            if (result_code[i] == result_code[i-1] )
            {
                if (i==1)
                    result.push_back(strs[0]);
                    
                result.push_back(strs[i]);
            }    

        }
        


        return result;
        
    }
};
