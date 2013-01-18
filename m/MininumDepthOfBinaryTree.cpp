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

    int getlength(TreeNode * root)
    {
        if (root == NULL)
            return 0;
        
        int left =
            getlength(root->left);
            
        int right = 
            getlength(root->right);
            
        if (left == 0 && right == 0)
            return 1;
        else if (right != 0 && left != 0)
        {
            if (right < left)
                return 1+right;
            else
                return 1+ left;
        }
        else if (right != 0)
            return right + 1;
        else 
            return left + 1;
            
    }

    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
            return 0;
        
        return getlength(root);
                
        
    }
};
