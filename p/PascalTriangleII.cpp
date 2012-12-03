#include <vector>
#include <stdio.h>

using namespace std;


class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int >result;
            int * buf = (int* ) malloc((rowIndex+2) * sizeof(int) );
            if (buf==NULL)
                return result;

            memset(buf, 0, (rowIndex+2) * sizeof(int));

            buf[0] = 1;

            for (int j=1; j<=rowIndex; j++)
            {
                for (int i=j; i>0 ; i--)
                {
                    buf[i] = buf[i-1] + buf[i];    
                }
            }


            for(int i=0; i<=rowIndex; i++)
            {
                result.push_back(buf[i]);
            }

            free(buf); buf=NULL;
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
