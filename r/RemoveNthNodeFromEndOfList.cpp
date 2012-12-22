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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
        
        if (n<=0)
            return NULL;
        
        ListNode * new_head = head;
        ListNode * p_pre = head;
        ListNode * p_remove = head;
        ListNode * p_before = NULL;
        
        int i=1;
        while(i<n) // point to node before remove
        {
            p_pre = p_pre->next;
            i++;
        }
        
        while(p_pre->next != NULL)
        {
            p_pre = p_pre->next;
            p_before = p_remove;
            p_remove = p_remove->next;
        }
        
        
        if (p_before == NULL) // in head
        {
            // bug here
            new_head = p_remove->next;
            
        }
        else if (p_remove == p_pre) // in end
        {
            p_before->next = NULL;
        }
        else // in middle
        {
            p_before->next = p_remove->next;
        }
        
        return new_head;
        
        
        
        
    }
};
