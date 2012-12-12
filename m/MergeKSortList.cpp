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

        int getone(vector<ListNode *> &lists,  ListNode ** one)
        {
            int min = 9999999;
            int offset = 0;

            for (int i=0; i<lists.size(); i++)
            {

                if (lists[i] != NULL)
                {
                    if (lists[i]->val < min)
                    {
                        min  = lists[i]->val;
                        offset = i;
                    }
                }

            }

            if (min == 9999999)
                return 0;

            *one = lists[offset];
            lists[offset] = lists[offset]->next;

            return 1;

        }

        ListNode *mergeKLists(vector<ListNode *> &lists) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int len = lists.size();
            if (len == 0)
                return NULL;
            if (len == 1)
                return lists[0];


            ListNode * head = NULL;
            ListNode * next = NULL;



            int ret = 1;
            while(ret )
            {
                ListNode *  one =NULL;
                ret = getone( lists, &one ) ;

                if (ret == 0) 
                    break;

                if (head == NULL)
                {
                    head = one;
                    head->next = NULL;
                    next = one;
                }


                next->next = one;
                // next->next->next = NULL;
                //next = next->next;
                next = one;
                next->next = NULL;
            }


            return head;
        }
};
