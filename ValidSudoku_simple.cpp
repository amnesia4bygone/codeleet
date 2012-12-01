class Solution {
    public:

        int is_dup(vector<char> &result)
        {
            if (result.size()<=1)
                return true;

            sort(result.begin(), result.end() );

            for (int i=0;i < result.size()-1; i++)
            {
                if (result[i] >= result[i+1])
                    return 0;
            }
            return 1;
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
                    {
                        //return false;
                    }
                    else
                        result.push_back(board[i][j]);
                }

                int x = is_dup(result);
                if (x==0) return false;
            }  


            for (int j=0; j< 9; j++)
            {
                result.clear();
                for (int i=0; i<9; i++)
                {
                    if (board[i][j] != '.')
                        result.push_back(board[i][j]);
                }

                int x = is_dup(result);
                if (x==0) return false;
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
                            if (board[x][y] != '.')
                                result.push_back(board[x][y]);                        
                        }

                    }
                    int x = is_dup(result);
                    if (x==0) return false;
                }

            }
            return true;
        }




        bool isValidSudoku(vector<vector<char> > &board) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function


            bool ret = isRightSukoku(board);
            return ret;
        }
};


