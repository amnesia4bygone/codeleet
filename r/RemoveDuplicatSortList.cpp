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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
        
        if (head->next == NULL)
            return head;
        
        ListNode * new_head = head;
        ListNode * write_node = head;
        ListNode * read_node = head->next;
        while( read_node != NULL )
        {
            if (read_node->val == write_node->val)
            {
                read_node = read_node->next;
            }
            else
            {
                write_node->next = read_node;
                write_node = write_node->next;
                read_node = read_node->next;
                
            }
        }
        write_node->next = NULL;
        
        return new_head;
        
    }
};
