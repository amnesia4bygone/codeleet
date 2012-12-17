class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int > result;
        
        
        int over = 0;
        int first_flag = 1;
        for(int i = digits.size()-1; i>=0; i--)
        {
            int x ;
            if (first_flag == 1)
            {
                x = digits[i] + 1 + over;
                first_flag = 0;
            }
            else
                x = digits[i] + over;
                
            if (x>=10)
            {
                over =1;
                x -= 10;
            }
            else
            {
                over = 0;
            }
            result.push_back(x);
        }
        if (over == 1)
        {
            result.push_back(over);
        }
        
        vector<int > tmp;
        for(int i=result.size() -1; i>=0; i--)
        {
            tmp.push_back(result[i]);
        }
        
        return tmp;
    }
};
