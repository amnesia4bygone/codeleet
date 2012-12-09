#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
    public:

        vector<vector<int> > result1;


        /*
           int calculate(vector<int> &segment)
           {

           }

           int find_result(void)
           {
        // find one contiguous segment, calculate it 

        int max=0;

        for(int i=0; i<result1[0].size(); i++)
        {
        vector<int> line = result[i];
        int start =-1;
        int len = 0;

        for (int j=0; j<line.size(); j++)
        {
        if (line[j] == 0)
        {
        vector<int> segment(line.begin()+ start, line.begin() + start + len-1);
        int tmp_max = 
        start = -1;
        len = 0 ;
        }
        else
        {
        if (start == -1)
        start = j;
        len++;
        }
        }
        }
        }*/

        int find_result(void)
        {
            int max = 0;
                printf("3333\n");

            for(int i=0; i<result1.size(); i++)
            {
                vector<int> line = result1[i];
                int max_num =0 ;
                for(int k=0; k<line.size(); k++)
                {
                    if( max_num < line[k])
                        max_num = line[k];
                }

                int len = 0;
                int start = 0;
                for (int k=1; k<=max_num; k++)
                {
                    int j=0;
                    while(j<line.size())
                    {
                        if(line[j] < k)
                        {
                            j++;
                            len = 0;
                        }
                        else
                        {
                            while( line[j] >=k )
                            {
                                len++;
                                j++;
                            }
                            if ( k * len > max)
                                max = k*len;
                        }
                    }
                }
            }
            printf("4444\n");

            return max;

        }

        void show(void)
        {
                for(int i=0; i<result1.size();i++)
                {
                        for(int j=0; j<result1[i].size();j++)
                        {
                                printf("%d", result1[i][j]);
                        }
                        printf("\n");
                }
        }

        void dump1(vector<vector<char> > &matrix)
        {
            printf("1111\n");
            vector<int> line ;
            for(int m=0; m<matrix[0].size(); m++)
            {
                if (matrix[0][m] == '0')
                    line.push_back(0);
                else
                    line.push_back(1);
            }
            result1.push_back(line);

            int line_num = matrix.size();
            printf("line_num %d\n", line_num);
            for (int i=1;  i<line_num; i++)
            {
                vector<int> line;
                for(int j=0; j<matrix[i].size(); j++)
                {
                    if( result1[i-1][j] == 0)
                    {
                        if (matrix[i][j] == '0' )
                            line.push_back(0);
                        else
                            line.push_back(1);
                    }
                    else
                    {
                        if (matrix[i][j] == '0' )
                            line.push_back(0);
                        else
                            line.push_back(1 + result1[i-1][j]);
                    }
                }
                result1.push_back(line);
            }
            printf("2222\n");
        }

        int maximalRectangle(vector<vector<char> > &matrix) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if( matrix.size() == 0)
                return 0;

            dump1(matrix);
                show();
            int max = 0;



            return find_result();
        }
};



vector<char> build(char * buf, int len)
{
        vector<char > result;
        for(int i=0; i<len; i++)
        {
                result.push_back(buf[i]);
        }
        return result;
}

int main(void)
{
        vector<vector<char> > matrix;
        vector<char> one;
       /* 
        one= build("10101110");
        matrix.push_back(one);
        one.clear();
        
        one = build("11011000");
        matrix.push_back(one);
        one.clear();

        one = build("11100101");
        matrix.push_back(one);
        one.clear();

        one = build("10111110");
        matrix.push_back(one);
        one.clear();

        one = build("00011110");
        matrix.push_back(one);
        one.clear();
*/
        int len = 12;
        one = build("101011011111", len);
        matrix.push_back(one);
        one.clear();
        one = build("110011101101",len);
        matrix.push_back(one);
        one.clear();
        one = build("010110100000", len);
        matrix.push_back(one);
        one.clear();
        one = build("001110001010",len);
        matrix.push_back(one);
        one.clear();

        one = build("101011110101", len);
        matrix.push_back(one);
        one.clear();

        one = build("111000000110",len);
        matrix.push_back(one);
        one.clear();

        one = build("010111011110",len);
        matrix.push_back(one);
        one.clear();
        one = build("011001001101", len);
        matrix.push_back(one);
        one.clear();
        one = build("101010011010",len);
        matrix.push_back(one);
        one.clear();
        one = build("011101000100",len);
        matrix.push_back(one);
        one.clear();

        Solution s;
        int x =s.maximalRectangle(matrix);
        printf("%d\n", x);
}
