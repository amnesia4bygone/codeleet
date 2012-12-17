/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    
    void connect_middle(TreeLinkNode * root)
    {
        if (root  == NULL)
            return;
        TreeLinkNode * left = root->left;
        TreeLinkNode * right = root->right;
        
        while (left != NULL && right != NULL)
        {
            left->next = right;
            left = left->right;
            right = right->left;
        }
    }
    
    void connect_right(TreeLinkNode * root)
    {
        if (root  == NULL)
            return;
            
        TreeLinkNode * right = root->right;
        while(right != NULL)
        {
            right->next = NULL;
            right = right->right;
        }
    }
    
    void build(TreeLinkNode *root)
    {
        if (root == NULL)
            return;
        
        connect_middle(root);
        
        build(root->left);
        
        build(root->right);        
    }
    
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        build(root);
        
        connect_right(root);
        
    }
};
