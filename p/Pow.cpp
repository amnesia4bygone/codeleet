class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n==1)
            return x;
        
        if (n==0)
            return 1;
        if (x==0)
            return 0;
        
        int flag = 1;
        if (n < 0)
        {
            flag = 0;
            n = -n;
            
        }
                    
        double result = 1;
        double tmp = x;
        
        int len = n;
        unsigned int offset = 1;
        
        while(offset)
        {
            if (len&offset)
                result = result * tmp;
            
            tmp = tmp * tmp;
            
            offset = offset<<1; 
        }
        
        
        if (flag)
            return result;
        else
        {
            double new_result = double(1/result);
            return new_result;
        }
            
        
    }
};
