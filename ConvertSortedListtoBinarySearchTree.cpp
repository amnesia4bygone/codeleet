/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //return NULL;
        
        if (head == NULL)
            return NULL;
        
        int len = 0;
        ListNode * tmp = head;
        while(tmp != NULL)
        {
            len++;
            tmp = tmp->next;
        }
        
        tmp = head;
        TreeNode * treehead = (TreeNode*) malloc(sizeof(TreeNode));
        
        if (len == 1)
        {
            treehead->val = tmp->val;
            treehead->left = NULL;
            treehead->right = NULL;
            return treehead;
        }
        
        
        if (len == 2)
        {
            TreeNode * treeright  = new TreeNode(tmp->val);
            treehead->val = tmp->next->val;
            //treeright->val = tmp->val;
            treehead->left = treeright;
            treehead->right = NULL;
            return treehead;
        }
        
        if (len == 3)
        {
            // bug here, should new
            TreeNode * treeright  = new TreeNode(tmp->val);
            TreeNode * treeleft  = new TreeNode(tmp->next->next->val);
            treehead->val  = tmp->next->val;
            
            treehead->left = treeright;
            treehead->right  = treeleft;
            return treehead;            
        }


        int mid = len/2;
        ListNode * lright = head;
        ListNode * lleft = NULL;
        
        TreeNode * tright = NULL;
        TreeNode * tleft = NULL;
        
        //                   // bug here, not malloc
        TreeNode * thead = (TreeNode * ) malloc(sizeof(TreeNode));
        
        int i=0;
        tmp = head;
        // bug here -1
        while(i < mid-1)
        {
            tmp = tmp->next;
            i++;
        }
        
        thead->val = tmp->next->val;
        
        lleft = tmp->next->next;
        tleft = sortedListToBST(lleft);
        
        tmp->next = NULL;
        tright = sortedListToBST(lright);
        
        thead->left = tright;
        thead->right = tleft;
        
        return thead;
           
            
    }
};
