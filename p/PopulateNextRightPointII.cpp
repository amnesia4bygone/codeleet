class Solution {
public:
        
  
    void connect(TreeLinkNode *root) {
        
        if (root== NULL)
            return;
        
        root->next = NULL;
        connect_i(root);
        
    }


    void connect_i(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return;
        
        TreeLinkNode * left  = root->left;
        TreeLinkNode * right = root->right;
        
        // bug here
        if (left == NULL && right == NULL)
            return;
            
        
        if (left != NULL)
            left->next = right;
        
        
        
        
        TreeLinkNode * other_root = root->next;
        
        if (other_root == NULL)
        {
            // bug here
            if (right!= NULL)
                right->next = NULL;
            
        }
        else
        {
            // bug here
            while(other_root->next != NULL )  
            {
                if( other_root->left == NULL && other_root->right == NULL )
                    other_root = other_root->next;
                else
                    break;
            }
            
            TreeLinkNode * neibo ;
            
            if (other_root == NULL)
                neibo = NULL;
            
            else if (other_root->left != NULL)
            {
                neibo = other_root->left;
            }
            else
            {
                neibo = other_root->right;
            }
            
            if (right != NULL)
            {
                if (other_root->left != NULL)
                {
                    right->next = neibo;
                }
                else
                {
                    right->next = neibo;
                }
            }
            else
            {
                if (other_root->left != NULL)
                {
                    left->next = other_root->left;
                }
                else
                {
                    left->next = other_root->right;
                }                
            }
        }
        
        // bug here...
        connect_i(right);
        connect_i(left);
            
        
    }
};
