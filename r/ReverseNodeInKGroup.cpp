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

    ListNode * reverseK(ListNode * head, int num, ListNode ** next,  ListNode ** tail)
    {
        // maybe num big then node num
        ListNode * new_head =NULL;
        ListNode * cur=NULL;
        int i=0;
        while(i<num)
        {
            cur = head;
            
            *next = head->next;
            head = head->next;
            
            if (new_head == NULL)
            {
                new_head =  cur;
                new_head->next = NULL;
                *tail = cur;
            }
            else
            {
                cur->next = new_head;
                new_head = cur;
            }
            
            i++;
        }
        return new_head;   
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL)
            return NULL;
        if (k <=1 )
            return head;
            
        int len=0;
        ListNode * tmp = head;
        while(tmp != NULL)
        {
            len++;
            tmp = tmp->next;
        }

        ListNode * pre = NULL;
        ListNode * cur_head = NULL;
        ListNode * cur_tail = NULL;
        ListNode * cur_next = NULL;
        ListNode * new_head  = head;
        
        ListNode * pre_tail = NULL;
        // bug here =
        while(len >= k)
        {
            pre_tail = cur_tail;
            if (pre == NULL)
            {
                new_head = reverseK(head, k, &cur_next, &cur_tail);
                pre = cur_next;
                cur_tail->next = NULL;
            }
            else
            {
                cur_head = reverseK(pre, k, &cur_next, &cur_tail);
                pre = cur_next;
                pre_tail->next = cur_head;
                cur_tail->next = NULL;
                
            }
                
            len -=k;
        }
        // bug here twice
        if (cur_tail != NULL)
            cur_tail->next = cur_next;
        
        return new_head;
        
    }
};
