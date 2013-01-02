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

    ListNode * swapTwoNode(ListNode * head, ListNode ** next)
    {
        if (head == NULL)
            return NULL;
        
        
        if (head->next == NULL)
        {
            *next = NULL;
            return head;
        }
        
        ListNode * p_one = head;
        ListNode * p_two = head->next;
        
        p_two->next = p_one;
        p_one->next = NULL;
        *next = p_one;
        return p_two;
        
    }
    
    ListNode * getNext(ListNode * head)
    {
        if (head == NULL)
            return NULL;
        
        ListNode * tmp = NULL;
        if (head->next != NULL)
            tmp = head->next;
        else
            return NULL;
        
        if (tmp->next != NULL)
            return tmp->next;
        else
            return NULL;
        
    }

    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
        
        
        ListNode * next = head;
        ListNode * new_head = NULL;
        ListNode * pre = head;
        ListNode * pre_head = NULL;
        
        while(next != NULL)
        {
            if (new_head == NULL)
            {
                
                next = getNext(pre);

                ListNode * tmp = NULL;
                new_head = swapTwoNode(pre, &tmp);
                if ( tmp)
                    tmp->next = next;
                else
                    new_head->next = NULL;
                
                /*if (pre->next)
                    pre_head = pre->next;
                else */
                pre_head = tmp;    
                pre = next;
                
            }
            else
            {
                next = getNext(pre);
                
                ListNode * tmp = NULL;
                ListNode * tmp_head = NULL;
                tmp_head = swapTwoNode(pre, &tmp);
                
                pre_head->next = tmp_head;
                pre_head = tmp;
                
                
                if (tmp)
                    tmp->next = next;
                else

                    tmp_head->next = NULL;
                    
                pre = next;
                
            }
        }
        return new_head;
    }
};
