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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > result;
        
        if (root == NULL)
            return result;
        
        vector<TreeNode* > stack;
        
        stack.push_back(root);
        
        int direct =1;
        
        
        while( !stack.empty() )
        {
            vector<TreeNode* > new_stack;
            vector<int> new_result;
            
            for( int i=stack.size()-1; i>=0; i--)
            {
                TreeNode * point = stack[i];
                new_result.push_back(point->val);
                
                if (direct == 0)
                {
                    if (point->right != NULL)
                        new_stack.push_back(point->right);
                    if (point->left != NULL)
                        new_stack.push_back(point->left);
                }
                else
                {
                    if (point->left != NULL)
                        new_stack.push_back(point->left);
                    if (point->right != NULL)
                        new_stack.push_back(point->right);
                }
            }
            
            if (direct == 0)
                direct = 1;
            else
                direct = 0;
            
            result.push_back(new_result);
            
            stack.clear();
            stack = new_stack;
  
        }
        
        return result;

        
    }
};
