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
    TreeNode * flat(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        
        if (root->left != NULL)
        {
            TreeNode * tmp;
            tmp = flat(root->left);
            root->left = NULL;
            
            
            TreeNode * tmp_tail = tmp;
            while(tmp_tail->right != NULL)
            {
                tmp_tail = tmp_tail->right;
            }
            
            tmp_tail->right = flat(root->right);
            root->right = tmp;
        }
        else
        {
            TreeNode * tmp = flat(root->right);
            root->right = tmp;
        }
        
        return root;
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flat(root);
    }
};
