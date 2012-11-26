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

    int getLength(TreeNode * node)
    {
         int leftdepth = 0; 
         int rightdepth = 0;
            
        if (node->left == NULL && node->right == NULL)
            return 1;
            
        if( node->left != NULL)
            leftdepth = getLength(node->left);
        if (node->right != NULL)
            rightdepth = getLength(node->right);
            
        if (leftdepth > rightdepth+1 || rightdepth > leftdepth+1)
            return -1;
        
        if (leftdepth < 0 || rightdepth < 0)
            return -1;
        
        if( leftdepth > rightdepth  ) 
            return leftdepth+1;
        else
            return rightdepth + 1;
    }  

    bool isBalanced(TreeNode *root) {
        

        
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return true;
            
        int x = getLength(root);
        
        if (x<0)
                return false;
        else
            return true;
        
    }
};
