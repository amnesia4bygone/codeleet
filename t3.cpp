class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int row_len =  triangle.size();
        
        if (row_len == 0 )
        {
            return 0;
        }
        
        
        if (row_len == 1)
            return triangle[0][0];
            
            
            
        
        vector<int> tmp;
        tmp.push_back( triangle[0][0] );
        vector<int> row;
        
        for (int i=1; i<row_len; i++)
        {
            
            int one_row_len = triangle[i].size();
            for (int k=0; k<one_row_len; k++)
            {
                int offset1 = k-1;
                int offset2 =  k;
                
                int val = 0;
                
                if (k == 0) 
                    val = tmp[offset2];
                else if (k== one_row_len-1)
                    val = tmp[offset1];
                else
                {
                    if (tmp[offset1] > tmp[offset2] )
                        val = tmp[offset2];
                    else
                        val = tmp[offset1];
                }
                
                row.push_back( triangle[i][k] + val );
            }
            
            if (i== row_len -1)
            {
                sort(row.begin(), row.end());
                return row[0];
            }
            
            tmp.clear() ;
            tmp = row;
            row.clear();
        
        }
        
        
        
    }
};
