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

        int dump(TreeNode * root, vector<int> & result)
        {
            if (root == NULL)
                return 0;

            if (root->left)
                dump(root->left, result);

            result.push_back(root->val);

            if (root->right)
                dump(root->right, result);

            return 1;

        }

        bool isSymmetric(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int > result;

            dump(root, result);

            if (result.size() <= 1)
                return true;

            int i=0; 
            int j=result.size() -1;

            while(i<j)
            {
                if (result[i] != result[j])
                    return false;
                i++;
                j--;
            }
            return true;

        }
};
