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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (inorder.size() == 0 )
            return NULL;
        
        if (inorder.size() != postorder.size() )
            return NULL;
        
        unsigned int len = postorder.size();

        TreeNode * root = (TreeNode *) malloc( sizeof(TreeNode) );
        if (root == NULL)
            return NULL;

        root->val = postorder[len-1];
        
        if (len == 1)
        {
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        
        int offset = -1;
        for(unsigned int i=0; i<len; i++)
        {
            if (inorder[i] == root->val)
            {
                offset = i;
                break;
            }
        }
        
        if (offset == 0)
        {
            vector<int> new_inorder;
            new_inorder.assign(inorder.begin()+1, inorder.end() );
            
            vector<int> new_postorder; 
            new_postorder.assign(postorder.begin(), postorder.end()-1);
            
            TreeNode * right = buildTree(new_inorder, new_postorder);
            
            root->right = right;
            root->left = NULL;
        }
        else if (offset == len-1)
        {
            vector<int> new_inorder;
            new_inorder.assign(inorder.begin(), inorder.end()-1 );
            
            vector<int> new_postorder;
            new_postorder.assign(postorder.begin(), postorder.end() -1);
            
            TreeNode * left = buildTree(new_inorder, new_postorder);
            
            root->right = NULL;
            root->left = left;           
        }
        else
        {
            vector<int> new_left_inorder;
            new_left_inorder.assign(inorder.begin(), inorder.begin() + offset  );
            vector<int> new_left_postorder ;
            new_left_postorder.assign(postorder.begin(), postorder.begin() + offset );
            TreeNode * left = buildTree(new_left_inorder, new_left_postorder);
            
            
            vector<int> new_right_inorder;
            new_right_inorder.assign(inorder.begin()+offset+1, inorder.end());
            
            vector<int> new_right_postorder;
            new_right_postorder.assign(postorder.begin() + offset, postorder.end() -1);
            TreeNode * right =  buildTree(new_right_inorder, new_right_postorder);
            
            root->right = right;
            root->left = left;             
        }
        
        return root;
        
    }
};
