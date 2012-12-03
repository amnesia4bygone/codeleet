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

        int route(TreeNode * root, int sum, vector<int > c_has, vector<vector<int> > &result)
        {
            vector<int>  has = c_has;


            if (root==NULL)
            {
                return 0;
            }

            has.push_back(root->val);
            if (root->left == NULL && root->right == NULL && sum == root->val)
            {
                result.push_back(has);
                return 1;

            }

            route(root->left, sum-root->val, has,  result);
            route(root->right, sum-root->val, has,  result);

            return 0;

        }

        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > result;
            vector<int > has;

            if (root == NULL)
                return result;

            has.push_back(root->val);
            if (root->left == NULL && root->right == NULL && root->val == sum)
            {

                result.push_back(has);
                return result;
            }

            route(root->left, sum-root->val, has, result);
            route(root->right, sum-root->val, has, result);

            return result;
        }
};
