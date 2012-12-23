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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) 
            return NULL;
        
        int len = 1;
        ListNode * tail = head;
        while(tail->next != NULL)
        {
            len++;
            tail = tail->next;
        }
        
        if (len == 1||k==0)
            return head;
        
        int new_k = k % len;
        
        if (new_k == 0)
            return head;
        
        int offset = len - new_k;
        
        ListNode * pre = NULL;
        ListNode * tmp = head;
        int i=0; 
        while(i<offset)
        {
            pre = tmp;
            tmp = tmp->next;
            i++;
        }
        
        ListNode * new_head = tmp;
        tail->next = head;
        pre->next = NULL;
        
        
        
        return new_head;
    }
};
