class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num = matrix.size();
        if (num == 0)
            return false;
        
        int len = matrix[0].size();
        if (len == 0)
            return false;
            
        int cur_row = -1;
        for(int i=0; i<num; i++)
        {
            if (matrix[i][0] > target)
                break;
            cur_row++;
        }
        
        if (cur_row == -1)
            return false;
        
        bool flag = false;
        for(int i=0; i<len; i++)
        {
            if (target == matrix[cur_row][i] ) 
                flag = true;
        }
        
        
        return flag;
    }
};
