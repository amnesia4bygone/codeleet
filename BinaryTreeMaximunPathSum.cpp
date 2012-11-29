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

    // no left + val + right
    int singlePathSum(TreeNode * root)
    {
        vector<int> result;
        
        if (root == NULL)
            return 0;
            
        if (root->left == NULL && root->right == NULL)
        {
                return root->val;
        }
        
        if (root->left == NULL)
        {
            result.push_back( root->val );
            result.push_back( root->val + singlePathSum(root->right)  );
            //result.push_back( singlePathSum(root->right) );
            
            sort(result.begin(), result.end()); 
            return result[ result.size()-1 ];
        }
        
        if (root->right == NULL)
        {
            result.push_back( root->val );
            result.push_back( root->val + singlePathSum(root->left)  );
            //result.push_back( maxPathSum(root->left) );
            
            sort(result.begin(), result.end()); 
            return result[ result.size()-1 ];
        }
        
        int left = singlePathSum(root->left);
        int right = singlePathSum(root->right);
        int val  = root->val;
        
        
        
        

        result.push_back(val);
        result.push_back(left + val);
        result.push_back(val + right);

        
        sort(result.begin(), result.end());
        
        return result[ result.size()-1 ];
                
    }

    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> result;
        
        if (root == NULL)
            return 0;
            
        if (root->left == NULL && root->right == NULL)
        {
                return root->val;
        }
        
        if (root->left == NULL)
        {
            result.push_back( root->val );
            result.push_back( root->val + maxPathSum(root->right)  );
            result.push_back( maxPathSum(root->right) );
            
            sort(result.begin(), result.end()); 
            return result[ result.size()-1 ];
        }
        
        if (root->right == NULL)
        {
            result.push_back( root->val );
            result.push_back( root->val + maxPathSum(root->left)  );
            result.push_back( maxPathSum(root->left) );
            
            sort(result.begin(), result.end()); 
            return result[ result.size()-1 ];
        }
        
        
        
        int left = maxPathSum(root->left);
        int right = maxPathSum(root->right);
        int val  = root->val;
        
        int single_left = singlePathSum(root->left);
        int single_right = singlePathSum(root->right);        
        
        result.push_back(left);
        result.push_back(right);
        result.push_back(val);
        result.push_back(single_left + val);
        result.push_back(val + single_right);
        result.push_back(single_left + val + single_right);
        
        sort(result.begin(), result.end());
        
        return result[ result.size()-1 ];
        
    }
};
