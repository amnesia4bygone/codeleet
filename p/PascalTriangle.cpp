#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int > one;
        vector<vector<int> >result;
        if (numRows<=0)
            return result;

        one.push_back(1);
        result.push_back(one);
        if (numRows == 1)
        {
            return result;
        }
        //return result;
        
        for (int i=1; i<numRows; i++)
        {
            vector<int> tmp;
            tmp.push_back(one[0]);
            
            for (int j=1; j<i; j++)
            {
                tmp.push_back(one[j-1] + one[j]  );   
            }
            
            tmp.push_back(one[i-1]);
            
            result.push_back(tmp);
            //one.clear();
            one = tmp;
            //tmp.clear();    
        }
        return result;
        
        
    }
};

int main(void)
{
 Solution s;
 vector<vector<int> > result;
 result = s.generate(5);
 for (int i=0; i<5; i++)
 {
        printf("------\n");
        for(int j=0; j<result[i].size(); j++)
        {
                printf("%d ", result[i][j]);
        }
        printf("------\n");
 }
 return 1;
}
