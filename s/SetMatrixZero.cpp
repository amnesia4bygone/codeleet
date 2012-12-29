class Solution {
public:

    int includeZero(vector<int> lines)
    {
        //int flag = 0;
        int len = lines.size();
        for(int i=0; i<len; i++)
        {
            if (lines[i] == 0)
                return 1;
        }
        return 0;
    }

    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mark_lines = -1;
        
        int row_num = matrix.size();
        if (row_num == 0)
            return;
        int col_num =  matrix[0].size();
           
        for(int i=0; i<row_num; i++)
        {
            int is_zero = includeZero( matrix[i] );
            if (is_zero == 0 && mark_lines == -1)
            {
                mark_lines = i;
                break;
            }
        }
        
        
        int base_lines = mark_lines;
        if (base_lines == -1)
            base_lines = 0;
        
        for(int i=0; i<row_num; i++)
        {
            if (mark_lines == i)
                continue;
            
            int is_zero = includeZero( matrix[i] );
            
            if (is_zero)
            {
                for(int j=0; j<col_num; j++)
                {
                    if ( matrix[i][j] == 0)
                        matrix[base_lines][j] = 0;
                    else    
                        matrix[i][j] = 0;
                }
            }
        }
        
        for(int i=0; i<col_num; i++)
        {
            if (matrix[base_lines][i] == 0)
            {
                for(int j=0; j<row_num; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        
        return;
    }
};
