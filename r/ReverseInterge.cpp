class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int flag = 1;
        unsigned int y = x;
        if (x < 0)
        {
            flag =0;
            y = x * -1;
        }
        
        int result = 0;
        
        while(y != 0)
        {
            result = result * 10;
            unsigned tmp = y % 10;
            result += tmp;
            y = y /10;
        }
        
        if (flag == 0)
            result *= -1;
        
        return result;
   
        
    }
};
