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
        int maxDepth(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function


            if (root == NULL)
                return 0;

            int left = 0;
            if (root->left)
                left = maxDepth(root->left);

            int right = 0;
            if (root->right)
                right = maxDepth(root->right);

            if (left > right)
                return left + 1;
            else
                return right + 1;
        }
};
