/*
"b", "" 1       1       
   
"a", "a"        0       0       
   
"a", "b"        1       1       
   
"a", "ab"       1       1       
   
"ab", "a"       1       1       
   
"ab", "bc"      2       2       
   
"sea", "ate"    1       3       
   
"sea", "eat"    1       2       
   
"mart", "karma" 3       3       
   
"park", "spake" 3       3       
   
"food", "money" 7       4       
   
"horse", "ros"  2       3       
   
"spartan", "part"       3       3       
   
"plasma", "altruism"    6       6       
   
"kitten", "sitting"     5       3       
   
"islander", "islander"  0       0       
"islander", "slander"   1       1       
"industry", "interest"  8       6       
"intention", "execution"        8       5       
"prosperity", "properties"      7       4       
"algorithm", "altruistic"

*/




class Solution {
public:


    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = word1.length();
        int len2 = word2.length();

        int i=0; 
        int j=0;

        int number = 0;
        while(i<len1 || j<len2)
        {
                if (word1[i] == word2[j])
                {
                        i++;
                        j++;
                }
                else if ( (len1-i) > (len2-j) )
                {
                        // delete here
                        number ++;
                        i++;
                }
                else if ( (len1-i) == (len2 - j)  )
                {
                        // replace here
                        number ++;
                        i++; j++;
                }
                else
                {
                        // delete here
                        number++;
                        j++;
                }
        }
        return number;
    }   
};

/*
class Solution {
public:

    int find_diff(vector<char > &c1, vector<char > &c2)
    {
        int i=0 ; 
        int j=0;
        
        int number = 0;
        
        while(i<c1.size() || j<c2.size())
        {
            if (i==c1.size() )
            {
                j++;
                number++;
                continue;
            }
            
            if (j == c2.size())
            {
                i++;
                number ++;
                continue;
            }
            
            if (c1[i] == c2[j])
            {
                i++;
                j++;
            }
            else if (c1[i] > c2[j] )
            {
                number ++;
                j++;
            }
            else
            {
                number ++;
                i++;
            }
            
        }
        return number;
    }

    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        //sort
        vector<char > c1;
        vector<char > c2;
        
        if (word1.length() == 0 && word2.length() == 0)
            return 0;
            
        if (word1.length() ==0 )
            return word2.length();
        
        if (word2.length() == 0)
            return word1.length();
        
        for(int i=0; i<word1.length(); i++)
        {
            char a = word1[i];
            c1.push_back(a);
        }
        for(int i=0; i<word2.length(); i++)
        {
            char a = word2[i];
            c2.push_back(a);
        }        
        
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        
        
        int number =0;
        
        //alian count insert / delete
        if (c1.size() == c2.size() )
        {
            for (int i=0; i<c1.size(); i++)
            {
                if (c1[i] != c2[i])
                    number++;
            }
            return number;
        }
        else 
        {
            return find_diff(c1, c2);
        }
    }   
}; */
