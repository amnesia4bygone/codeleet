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

    int find_min(TreeNode * root, TreeNode ** point)
    {
        int ret = 999999;
        if (root == NULL)
        {
            *point = NULL;
            return ret;
        }
        
        TreeNode * p_left;
        TreeNode * p_right;
        
        int left = find_min(root->left, &p_left);
        int right = find_min(root->right, &p_right);
        
        if (root->val < left && root->val < right)
        {
            *point = root;
            return root->val;
        }
        else if (left < right)
        {
            *point = p_left;
            return left;
        }
        else
        {
            *point = p_right;
            return right;
        }
    }
    
    int find_max(TreeNode * root, TreeNode ** point)
    {
        int ret = -999999;
        if (root == NULL)
        {
            *point = NULL;
            return ret;
        }
        
        TreeNode * p_left;
        TreeNode * p_right;
        
        int left = find_max(root->left, &p_left);
        int right = find_max(root->right, &p_right);
        
        if (root->val > left && root->val > right)
        {
            *point = root;
            return root->val;
        }
        else if (left > right)
        {
            *point = p_left;
            return left;
        }
        else
        {
            *point = p_right;
            return right;
        }
    }
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL)
            return;
        
        TreeNode * p_left;
        TreeNode * p_right;
        int tmp;
        
        int left = find_max(root->left, &p_left);
        int right = find_min(root->right, &p_right);
        
        
        if (root->val < left && root->val > right)
        {
            tmp = p_left->val;
            p_left->val = p_right->val;
            p_right->val = tmp;
        }
        else if (root->val > left && root->val < right )
        {
            recoverTree(root->left);
            recoverTree(root->right);
        }
        else if (root->val < left)
        {
            tmp = p_left->val;
            p_left->val = root->val;
            root->val = tmp;
        }
        else
        {
            tmp = p_right->val;
            p_right->val = root->val;
            root->val = tmp;            
        }
        
        return;   
    }
};
