class Solution {
public:


    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         vector<int> result ;
        if (n==0)
        {

            result.push_back(0);
            return result;
        }
        
        if (n==1)
        {

            result.push_back(0); 
            result.push_back(1);
            return result;
        }
        
        
        result = grayCode(n-1);
        
        int total = 1;
        total = total<<(n-1);
        
        for(int i=result.size()-1; i>=0; i--)
        {
            result.push_back(total + result[i]);   
        }
        return result;
        
    }
};
