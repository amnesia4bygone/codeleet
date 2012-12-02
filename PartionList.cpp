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
        ListNode *partition(ListNode *head, int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode * less = NULL;
            ListNode * p_less = NULL;
            ListNode * greater = NULL;
            ListNode * p_greater = NULL;

            if (head == NULL)
                return NULL;

            ListNode * p = head;
            while(p != NULL)
            {
                if (p->val < x )
                {
                    if (less == NULL)
                    {
                        less = p;
                        p_less = p;
                        p = p->next;
                        p_less->next = NULL;

                    }   
                    else
                    {
                        p_less->next = p;
                        p = p->next;
                        p_less->next->next  = NULL;
                        p_less = p_less->next;
                    }

                }
                else
                {
                    if (greater == NULL)
                    {
                        greater = p;
                        p_greater = p;
                        p = p->next;
                        p_greater->next = NULL;
                    }
                    else
                    {
                        p_greater->next = p;
                        p = p->next;
                        p_greater->next->next  = NULL;

                        p_greater = p_greater->next;
                    }
                }

            }
            if (less == NULL)
                return greater;

            p_less->next = greater;

            return less;
        }
};
