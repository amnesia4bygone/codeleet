class Solution {
public:

    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( matrix.size() <= 1)
            return;
        
        int loop_num = matrix.size();
	// bug for loop_num        
        for (int i=0; i< loop_num/2; i++)
        {
            int offset_x = i;
            int offset_y = i;
            int len = loop_num - 2*i;
            // bug for len -1
            for(int k=0; k<len-1; k++)
            {
                // bug, x y is miss used. 
                int y1 = offset_x + k ;
                int x1 = offset_y ;
                
                int y2 = offset_x + len -1;
                int x2 = offset_y + k ;
                
                int y3 = offset_x + len - k -1;
                int x3 = offset_y + len -1;
                
                int y4 = offset_x ;
                int x4 = offset_y + len - k -1 ;
                
                
                int tmp = matrix[x1][y1];
                matrix[x1][y1] = matrix[x4][y4];
                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = tmp;
            }
        }
        
        
    }
};
