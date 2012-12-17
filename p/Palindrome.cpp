class Solution {
public:



    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x<0)
            return false;
        
        if (x<10)
            return true;
        
        int new_x = 0;
        int tmp = x;
        
        while(tmp>0)
        {
            new_x *= 10;
            new_x += tmp%10;
           
            tmp /= 10;
        }
        
        if (new_x != x)
            return false;
        else
            return true;
    }
};
