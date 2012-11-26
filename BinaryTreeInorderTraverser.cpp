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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        
        if (root == NULL)
            return result;
        
        if (root->left == NULL && root->right == NULL)
        {
            result.push_back(root->val);
            return result;
        }
        
        if (root->left == NULL)
        {
            result.push_back(root->val);
            
            vector<int> left = inorderTraversal(root->right);
            for (int i=0; i<left.size(); i++)
                result.push_back(left[i]);
                
            return result;
            
        }
        
        if (root->right == NULL)
        {
            
            
            vector<int> left = inorderTraversal(root->left);
            for (int i=0; i<left.size(); i++)
                result.push_back(left[i]);
            
            result.push_back(root->val);
            
            return result;
        }
        
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        
        for (int i=0; i<left.size(); i++)
            result.push_back(left[i]);
        
        result.push_back(root->val);
        
        for(int i=0; i<right.size(); i++)
            result.push_back(right[i]);
            
        return result;
        
        
    }
};
