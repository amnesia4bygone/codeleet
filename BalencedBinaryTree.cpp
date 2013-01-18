/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
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
    int return_depth(TreeNode * root)
    {
        if (root==NULL)  return 0;
        
        int left = return_depth(root->left);
        
        int right = return_depth(root->right);
        
        if (left > right)
            return 1+left;
        else
            return 1+right;
    }

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL)
            return true;
        
        int left = return_depth(root->left);
        int right = return_depth(root->right);
        
        if ( abs(left-right) > 1 )
        {
            return false;
        }
        
        if (0 == isBalanced(root->left) )
            return false;

        if (0 == isBalanced(root->right) )
            return false;
        
        return 1;
        
        
    }
}; 
 

