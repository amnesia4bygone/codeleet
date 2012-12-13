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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (l1 == NULL)
            return l2;
        
        if (l2 == NULL)
            return l1;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        ListNode * head = NULL;
        ListNode * cur = NULL;
               
        if (t1->val < t2->val)
        {
            head = t1;
            cur = t1;
            t1 = t1->next;
            cur->next = NULL;
        }
        else
        {
            head = t2;
            cur = t2;
            t2 = t2->next;
            cur->next = NULL;
        }
        
        
        while(t1 != NULL || t2 != NULL)
        {
            //ListNode * tmp = NULL;
            if (t1 == NULL)
            {
                cur->next = t2;
                return head;
            }
            
            if (t2 == NULL)
            {
                cur->next = t1;
                return head;
            }
            
            if (t1->val < t2->val)
            {
                cur->next = t1;
                t1 = t1->next;
                cur = cur->next;
                cur->next = NULL;
            }
            else
            {
                cur->next = t2;
                t2 = t2->next;
                cur = cur->next;
                cur->next = NULL;
            }
            
        }
        return head;
    }
};
