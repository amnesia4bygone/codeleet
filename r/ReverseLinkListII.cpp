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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head==NULL)
            return NULL;
        if (n==m || n==1)
            return head;
            
        ListNode * pre = NULL; // node before reverse 
        ListNode * tmp = head;
        ListNode * reverse_end = head;
        
        for(int i=0; i<m-1 ;i++)
        {
            pre = tmp;
            tmp = tmp->next;
        }
        
        ListNode * reverse_head = NULL;
        ListNode * tail = NULL;
        ListNode * cur = NULL;
        int i=0; 
        while(i < (n-m+1))
        {
            tail = tmp->next;
            cur = tmp;
            tmp = tmp->next;
            
            if (reverse_head == NULL)
            {
                reverse_head = cur;  
                reverse_head->next = NULL;
                reverse_end = cur;
            }
            else
            {
                cur->next = reverse_head;
                reverse_head = cur;
            }
            i++;
        }
        
        reverse_end->next = tail;
        
        if (m==1)
        {
            return reverse_head;
        }
        else
        {
            pre->next = reverse_head;
            return head;
        }
        
        
    }
};
