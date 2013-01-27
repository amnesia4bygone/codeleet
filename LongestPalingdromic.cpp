#include <string>
#include <vector>
#include <stdio.h>

using namespace std;


class Solution {
public:

    int isPalindrome(string s)
    {
        int len = s.length();
        
        int begin =0; 
        int end = len-1;
        
        while(begin < end)
        {
            if (s[begin] == s[end])
            {
                begin++;
                end--;
            }
            else
                return 0;
        }
        return 1;
    }


    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        int max_len = 0;
        
        int len = s.length();
        if (len == 0)
            return result;
        
        if (len == 1)
            return s;
            
        vector<string> M(len+1 );
        
        string tmp(1, s[0]);
        M[1] = tmp;
        
        // i offset
        for(int i =1; i<len; i++)
        {
            string one = M[i];
            int cur = i; 
            int first = i - M[i].length() -1;
            string tmp(1, s[i]);
            M[i+1] = tmp;
            
            
            if (first >= 0) 
            {
                if (s[first] == s[cur])
                {
                    string new_one = s[first] + one + s[i];
                    M[i+1] = new_one;
                    
                    if (new_one.length() > result.length() )
                        result = new_one;
                }
                else
                {
                    int flag = 0;
                    // j=offset
                    for(int j=0; j<one.length(); j++)
                    {
                        string new_one(one, j);
                        new_one += s[i];
                        
                        if (1 == isPalindrome(new_one) )
                        {
                            flag = 1;
                            M[i+1] = new_one;
                                                
                            if (new_one.length() > result.length() )
                                result = new_one;
                            break;
                        }
                    }
                    //if (flag == 0)
                    //    M[i+1] = one;
                }
            }
            else
            {
                int flag = 0;
                for(int j=0; j<one.length(); j++)
                {
                    string new_one(one, j);
                    new_one += s[i];
                    
                    if (1 == isPalindrome(new_one) )
                    {
                        flag = 1;
                        M[i+1] = new_one;
                        
                        if (new_one.length() > result.length() )
                            result = new_one;
                        break;
                    }
                }
                //if (flag == 0)
                //    M[i+1] = one;
            }
            
            
            
            
        }
        
        return result;
    }
};

int main(void)
{
        string s("banana");
	string b1("ana");
	string b2("a");
	string b3("anab");
	string b4("anana");
	string b5("anacana");
        Solution ss;
        printf("%s\n", ss.longestPalindrome(s).c_str()  );
        printf("%d\n", ss.isPalindrome(b1)  );
        printf("%d\n", ss.isPalindrome(b2)  );
        printf("%d\n", ss.isPalindrome(b3)  );
        printf("%d\n", ss.isPalindrome(b4)  );
        printf("%d\n", ss.isPalindrome(b5)  );
        return 1;
}
