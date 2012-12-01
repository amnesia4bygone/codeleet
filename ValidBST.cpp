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

        int preorder(TreeNode *root, vector<int> &result)
        {
            if (root == NULL)
                return 0;

            if (root->left != NULL)
                preorder(root->left, result);


            result.push_back(root->val);

            if (root->right != NULL)
                preorder(root->right, result);

            return 0;
        }


        bool isValidBST(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function


            vector<int > result;

            preorder(root, result);

            if (result.size() <= 1)
                return true;


            for(int i = 0; i<result.size()-1; i++)
            {
                if (result[i] >= result[i+1])
                    return false;
            }
            return true;
        }
};
