#include <vector>
#include <algorithm>
#include <stdio.h>
using  namespace std;


class Solution {
    public:

        void dump(vector<vector<char> > &board)
        {
            printf("---------------\n");
            for(int i=0; i<9; i++)
            {
                for (int j=0; j<9; j++)
                {
                    printf("%c", board[i][j]);
                }
                printf("\n");
            }
            printf("---------------\n");
        }
        
        vector<char> find_number(vector<vector<char> > &board, int row, int col)
        {
            vector<char> result;
            for (int i=0; i<9; i++)
            {
                if ( board[row][i] != '.' )
                    result.push_back(board[row][i]);

                if (board[i][col] != '.')
                    result.push_back(board[i][col] );
            }

            int x = row/3;
            int y = col/3;

            for (int i=x*3; i<x*3 + 3; i++)
            {
                for (int j=y*3; j<y*3+3; j++)
                {
                    result.push_back(board[i][j]);
                }
            }

            vector<char> tmp;
            vector<char>::iterator it;
            for (char i='1'; i<='9'; i++)
            {
                it = find(result.begin(), result.end(), i );
                if (it == result.end())
                    tmp.push_back(i);
            }
            printf("%d\n", tmp.size());
            return tmp;
        }

        // board is global / result is for these cell
        bool isRightSukoku(vector<vector<char> > &board ) //, vector<vector<char> > &result, int row, int col)
        {   
            vector<char> result;

            for (int i=0; i< 9; i++)
            {
                result.clear();
                for (int j=0; j<9; j++)
                {
                    if (board[i][j] == '.')
                        return false;
                    else
                        result.push_back(board[i][j]);
                }

                sort(result.begin(), result.end() );
                if( result[0] != '1' || result[8] != '9' || result[3] != '4')
                    return false;
            }  


            for (int j=0; j< 9; j++)
            {
                result.clear();
                for (int i=0; i<9; i++)
                {
                    if (board[i][j] == '.')
                        return false;
                    result.push_back(board[i][j]);
                }
                sort(result.begin(), result.end() );
                if( result[0] != '1' || result[8] != '9' || result[3] != '4')
                    return false;
            }


            for (int i=0; i< 3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    result.clear();
                    for (int x=i*3; x<i*3+3; x++)
                    {
                        for (int y=j*3; y<j*3+3; y++)
                        {          
                            if (board[x][y] == '.')
                                return false;
                            result.push_back(board[x][y]);                        
                        }

                    }
                    sort(result.begin(), result.end() );
                    if( result[0] != '1' || result[8] != '9' || result[3] != '4')
                        return false; 
                }

            }
            return true;
        }



        int  solute_one_dot(vector<vector<char> > &board)//, vector<vector<char> > &result)
        {
            int x=-1;
            int y=-1;

            dump(board);

            for (int i=0; i< 9; i++)
            {
                for (int j= 0; j< 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        x=i;
                        y=j;
                        goto OUT;
                    }
                }
            }
OUT:
            bool ret = isRightSukoku(board);
            if (ret == true)
                return 1;


            if (x==-1 && y==-1 )
                return 1;

            vector<char> one_cell_result = find_number(board, x, y);

            if (one_cell_result.size() == 0) // 无解
                return -1;

            vector<vector<char> > cur_road = board;
            for (int i=0 ; i<one_cell_result.size(); i++)
            {
                cur_road[x][y] = one_cell_result[i];

                int ret = solute_one_dot(cur_road);
                if (ret == 1)
                    return 1;
            }

            return -1;


        }




        bool isValidSudoku(vector<vector<char> > &board) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            bool ret = isRightSukoku(board);
            if (ret == true)
                return true;

            int x  = solute_one_dot(board);

            if (x == -1)
                return false;

            return true;
        }
};




int main(void)
{
        vector<vector<char> > board;
        vector<char> one;

        one.push_back('1');
        one.push_back('.');
        one.push_back('.');
        one.push_back('.');
        one.push_back('.');
        one.push_back('.');
        one.push_back('.');
        one.push_back('.');
        one.push_back('.');

        board.push_back(one);
        board.push_back(one);
        board.push_back(one);
        board.push_back(one);
        board.push_back(one);
        board.push_back(one);
        board.push_back(one);
        board.push_back(one);
        board.push_back(one);

        Solution s;
        int ret = s.isValidSudoku(board);

        printf("xxx-%d\n", ret);
        return 1;
}
