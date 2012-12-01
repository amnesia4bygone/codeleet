#include <string>
using namespace std;

class Solution {
    public:

        int data[1000][1000];


        int min(int x, int y, int z)
        {
            if (x < y && x<z)
            {
                return x;
            }
            else if (y<z)
            {
                return y;
            }
            else
                return z;
        }

        int f(char x, char y)
        {
            if (x==y)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        int cal(string word1, string word2)
        {
            int len1 = word1.length();
            int len2 = word2.length();

            if (len1==0 && len2 == 0)
                return 0;

            if (len1==0)
                return len2;

            if (len2 == 0)
                return len1;


            if (word1[0] == word2[0])
                data[1][1] = 0;
            else
                data[1][1] = 1;

            data[0][0] = 0;
            data[0][1] = 1;
            data[1][0] = 1;


            int i=1;
            int j=1;
            int flag = 0;

            for (int i=1; i<=len1; i++)
            {   
                for (int j=1; j<=len2; j++)
                {
                    //printf("--%d %d--\n", i, j);
                    int I1 = data[i-1][j] + 1;

                    int J1 = data[i][j-1] + 1;

                    int I1J1 = data[i-1][j-1] + f(word1[i-1], word2[j-1]);

                    data[i][j] = min(I1, J1, I1J1);
                    //printf("--%d %d = %d %d %d--\n", i,j,I1, J1, I1J1);
                }
            }

            return data[len1][len2];

        }

        int minDistance(string word1, string word2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            for(int i=0; i<1000; i++)
            {
                for(int j=0; j<1000; j++)
                {
                    data[i][j] = 99999;
                }
            }      

            return cal(word1, word2);
        }
};



#if 0
int main(void)
{
        string a("park");
        string b("spake");
        Solution s;
        int x = s.minDistance(a, b);
        printf("--%d--\n", x);
        return 0;
}
#endif

