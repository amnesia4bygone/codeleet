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
        vector<int> getTreeSum(TreeNode * root)
        {
            vector<int> result;
            vector<int> left;
            vector<int> right;

            if (root == NULL)
            {
                //result.push_back(0);
                return result;
            }

            left = getTreeSum(root->left);
            right = getTreeSum(root->right);

            for(int i=0; i<left.size(); i++)
            {
                result.push_back( left[i] + root->val );
            }

            for(int i=0; i<right.size(); i++)
            {
                result.push_back( right[i] + root->val );
            }

            if (root->left==NULL && root->right ==NULL)
                result.push_back(root->val);

            return result;

        }

        bool hasPathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function


            if (root == NULL)
                return false;

            vector<int > result = getTreeSum(root);

            for (int i=0; i<result.size(); i++)
            {
                if (result[i] == sum)
                    return true;
            }
            return false;

        }
};
