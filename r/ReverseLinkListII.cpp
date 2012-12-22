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
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            if (m==n)
                return head;

            if (head == NULL)
                return NULL;

            ListNode * p_m = head;
            ListNode * p_m_pre = NULL;

            ListNode * p_n = head;
            ListNode * p_n_pre = NULL;

            ListNode * tmp_head = head;




            int len=1;

            int i=1;
            while( i<n && p_n != NULL)
            {
                if ( i<m && p_m != NULL)
                {
                    p_m_pre = p_m;
                    p_m = p_m->next;
                }

                p_n_pre = p_n;
                p_n = p_n->next;
                i++;
                len++;
            }

            // only 2 number
            if (len==2)
            {
                tmp_head = p_n;
                p_n->next = p_m;
                p_m->next = NULL;
                return tmp_head;
            }



            //m==1
            if (p_m_pre == NULL)
            {
                tmp_head = p_n;
                ListNode * tmp = p_m->next;
                p_n_pre->next = p_m;
                p_m->next = p_n->next;
                p_n->next = head->next;


                return tmp_head;
            }

            // m +1 == n
            if (p_m == p_n_pre)
            {
                ListNode * tmp = p_n->next;
                p_m_pre->next = p_n->next;
                p_n->next = p_m;
                p_m->next = tmp;
                return head;
            }


            // normal 
            ListNode * tmp = p_m->next;
            p_m_pre->next = p_n;
            p_m->next = p_n->next;
            p_n_pre->next = p_m;
            p_n->next = tmp; 

            return head;
        }
};
