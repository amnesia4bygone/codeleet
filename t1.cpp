#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> result;
        
        int len = words.size();
        
        if ( L==0)
            return result;
        
        if (len == 0)
        {
            string tmp;
            for (int x=0 ; x<L ; x++)
                tmp += " ";
            result.push_back(tmp);
            return result;
        }

        if (len ==1 && words[0].length() == 0)
        {
            string tmp;
            for (int x=0 ; x<L ; x++)
                tmp += " ";
            result.push_back(tmp);
            return result;            
        }
        
        int used_word_number = 0;
        
        while(used_word_number < len)
        {
            string one;
            int char_len = 0;
            
            while(char_len < L)
            {            
                int number = 0;
                
                int length = words[used_word_number].length();
                
                if (length == 0)
                {
                    used_word_number++;
                }
                
                else if (char_len + length < L-1 )
                {
                    // push one
                    if (number == 0)
                    {
                        one = words[used_word_number];
                        char_len = length;
                        number = 1;
                    }
                    else
                    {
                        one  += " " ;
                        one  += words[used_word_number]; 
                        char_len += length + 1;
                    }
                    used_word_number++;
                    
                }
                else
                {
                    // ident 
                    int x =  L - char_len;
                    for (int k=0; k<x; k++)
                        one += " ";
                    char_len += x;
                    
                }
                
                if (used_word_number == len)
                {
                    int x =  L - char_len;
                    for (int k=0; k<x; k++)
                        one += " ";
                    char_len += x;                    
                }
            }
            
            
            result.push_back(one);
        }
        return result;
    }
};

int main(void)
{
       string x;
        x.push_back("");
        solution x;
        vector<string > result = x.fullJustify(x, 1); 
       
}
