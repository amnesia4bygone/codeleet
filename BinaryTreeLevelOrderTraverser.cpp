/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >  result;
        
        if (root==NULL)
            return result;
        
        vector<int> result_level_0;

        
        if (root->left == NULL && root->right == NULL)
        {
           
            result_level_0.push_back(root->val);
            result.push_back( result_level_0);
            return result;
        }
        
        if (root->left == NULL)
        {
            result_level_0.push_back(root->val);
            result.push_back(result_level_0);
            
            vector<vector<int> >  child_result =  levelOrder(root->right);
            
            for (int i=0; i<child_result.size(); i++)
            {
                result.push_back( child_result[i]);
            }
            return result;
        }

        if (root->right == NULL)
        {
            result_level_0.push_back(root->val);
            result.push_back(result_level_0);
            
            vector<vector<int> >  child_result =  levelOrder(root->left);
            
            for (int i=0; i<child_result.size(); i++)
            {
                result.push_back( child_result[i]);
            }
            return result;
        }
        
        result_level_0.push_back(root->val);
        result.push_back(result_level_0);        

        vector<vector<int> >  child_result_left =  levelOrder(root->left);
        vector<vector<int> >  child_result_right = levelOrder(root->right);
        
        int left_len   = child_result_left.size();
        int right_len  = child_result_right.size();
        
        for (int i=0, j=0; i<left_len || j<right_len; i++, j++)
        {
            if (i<  left_len && j<right_len )
            {
                for (int k =0 ; k< child_result_right[j].size(); k++)
                    child_result_left[i].push_back( child_result_right[j][k] );
                result.push_back( child_result_left[i]  );
            }
            else if ( i< left_len)
            {
                result.push_back( child_result_left[i] );
            }
            else if (j < right_len)
            {
                result.push_back( child_result_right[j] );
            }
            else
            {
                //
            }
            
        }
        return result;
        
        

    }
};
