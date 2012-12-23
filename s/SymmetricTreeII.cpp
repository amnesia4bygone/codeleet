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


        bool isSymmetric(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<TreeNode * > left;
            vector<TreeNode * > right;


            if (root == NULL)
                return true;

            if (root->left == NULL && root->right == NULL)
                return true;


            left.push_back(root->left);
            right.push_back(root->right);

            while(left.size() != 0 && right.size() != 0 && right.size() == left.size())
            {
                TreeNode * p_left = left[left.size() -1];
                TreeNode * p_right = right[right.size() -1];
                left.pop_back();
                right.pop_back();


                if(p_left == NULL && p_right == NULL)
                {

                }
                else if (p_left != NULL && p_right != NULL)
                {
                    if (p_left->val != p_right->val)
                        return false;
                    left.push_back(p_left->left);
                    left.push_back(p_left->right);


                    right.push_back(p_right->right);
                    right.push_back(p_right->left);
                }
                else
                {
                    return false;
                }


            }

            if (left.size() == 0 && right.size() == 0)
                return true;
            else
                return false;
        }
};
