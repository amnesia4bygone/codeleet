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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * p_result = NULL;
        ListNode * p_tmp = NULL;
        
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
            
        ListNode * tmp_l1 = l1;
        ListNode * tmp_l2 = l2;
        
        int next_val = 0;
        while(tmp_l1 != NULL || tmp_l2 != NULL || next_val != 0)
        {
            int v1 = 0;
            int v2 = 0;
            
            if (tmp_l1 != NULL)
                v1 = tmp_l1->val;
            if (tmp_l2 != NULL)
                v2 = tmp_l2->val;
            
            int new_val = v1 + v2 + next_val;
            
            if (new_val >= 10)
            {
                new_val -= 10;
                next_val = 1;
            }
            else
            {
                next_val = 0;
            }
            
            ListNode*  p_one = (ListNode *) malloc(sizeof(ListNode));
            p_one->val = new_val;
            p_one->next = NULL;
            
            if ( p_result == NULL)
            {
                p_result = p_one;
                p_tmp = p_result;
            }
            else
            {
                p_tmp->next = p_one;
                p_tmp = p_one;
            }
            
            if (tmp_l1) tmp_l1 = tmp_l1->next;
            if (tmp_l2) tmp_l2 = tmp_l2->next;
        }
        return p_result;
    }
};
