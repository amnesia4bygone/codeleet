class Solution {
public:



    string deal_five(int x, string c, string pre)
    {
        string result;
        if( x == 0)
            return "";
        
        if (x<= 3)
        {
            for(int i=0; i<x; i++)
                result += pre;
            return result;
        }
        
        if (x == 4)
        {
            result = pre + c;
            return result;
        }
        
        if (x == 5)
        {
            result = c;
            return result;
        }
        
        if (x<9)
        {
            result = c;
            for(int i=6; i<=x; i++)
                result += pre; 
            return result;
        }
        
        
    }

    
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        string s;
        int t = num / 1000;
        
        for(int i=0; i<t; i++)
            s += "M";
        
        int h = num % 1000;
        h = h/100;
        
        if (h<9)
            s += deal_five(h, string("D"), string("C") );
        else
            s += string("CM");
        
        int tt = num % 100;
        tt = tt/10;
        if (tt<9)
            s += deal_five(tt, string("L"), string("X") );
        else
            s += string("XC");
            
        int o = num % 10;
        
        if (o < 9 )
            s += deal_five(o, string("V"), string("I") );
        else
            s += string("IX");
        
        
        
        
        
        return s;
    }
};
