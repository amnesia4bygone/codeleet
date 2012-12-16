

class Solution {
public:

    int is_right_position(vector< vector<int> >cur, int row, int col, int n)
    {
        //printf("---%d %d\n", row, col); 
        for (int i=0; i<row-1; i++)
        {
            if (cur[i][col] == 1)
                return 0;
        }

        int offset = 1;
        for(int i=row-2; i>=0; i--)
        {
            int left = col-offset;
            int right = col + offset;

            if (left >=0  &&  cur[i][left] == 1)
                return 0;

            if (right <= n && cur[i][right] == 1 )
                return 0;
            offset++;
        }

        return 1;
    }


     
    // one step, add one line
    void onestep(vector< vector<int> >cur, vector<vector<vector<int> > >&result, int n)
    {
        int len = cur.size();
        //printf("---%d\n", len); 
        if (len == n-1)
        {
            for(int i=0; i<n;i++)
            {
                if (is_right_position (cur, len+1, i, n)  )
                {
                    vector<int> new_row (n, 0);
                    new_row[i] = 1;

                    vector< vector<int> >cur_now = cur;
                    cur_now.push_back(new_row);
                    result.push_back(cur_now);
                }
            }            
        }
        else
        {
            for(int i=0; i<n;i++)
            {

                if (is_right_position(cur, len+1, i, n) )
                {
                    //printf("---%d %d avail \n", len, i);
                    vector<int> new_row (n, 0);
                    new_row[i] = 1;

                    vector< vector<int> >cur_now = cur;
                    cur_now.push_back(new_row);
                    onestep(cur_now, result, n);
                }
                //printf("---%d %d run \n", len, i); 
            }
        }
    }
    

    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<vector<int> > >result;
        vector<vector<int> > cur_map;
        vector<vector<string> > res;

        if (n<=0)
            return res;
        
        if (n==1)
        {
            string s("Q");
            vector<string> one;
            one.push_back(s);
            res.push_back(one);
            return res;
        }
        


        onestep(cur_map, result, n);
        
        
        for(int i=0; i<result.size(); i++)
        {
            vector<string> one_str;
            for(int j=0; j<result[i].size(); j++)
            {
                string one;
                for (int k=0; k<result[i][j].size(); k++)
                {
                    if (result[i][j][k] == 1 )
                        one += 'Q';
                    else
                        one += '.';
                }
                one_str.push_back(one);
            }
            res.push_back(one_str);
        }

        return res;
        

        
    }
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result = solveNQueens( n);
        return result.size();
    }
};

