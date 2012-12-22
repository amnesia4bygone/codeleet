/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
        
        if (head->next == NULL)
            return head;
        
        ListNode * new_head = NULL;
        ListNode * read_node = head;
        ListNode * p_next = NULL;
        ListNode * p_pre = NULL;
        
        while(read_node != NULL)
        {
            int pre;
            int next;
            // bug here
            if (p_pre == NULL )
                pre = -999999;
            else
                pre = p_pre->val;
                
            if (read_node->next == NULL)
                next = 999999;
            else
                next = read_node->next->val;
            
            if (read_node->val != pre && read_node->val != next)
            {
                if (new_head == NULL)
                {
                    new_head = read_node;
                    p_next = read_node;
                    //p_pre = read_node;
                    
                }
                else
                {
                    p_next->next = read_node;
                    p_next = read_node; //p_next->next;
                    //p_pre = read_node;
                }
            }
            else
            {
                // maybe free dup note
                
            }
            p_pre = read_node;
             read_node = read_node->next;
            
            
        }
        // bug here
        if (p_next != NULL)
            p_next->next = NULL;
        return new_head;
    }
};
