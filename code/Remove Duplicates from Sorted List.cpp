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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == NULL) return NULL;
        ListNode *p = head, *q;
        while(p->next != NULL)
        {
            if (p->next->val == p->val)
            {
                q = p->next;
                p->next = q->next;
                delete q;
            }
            else p = p->next;
        }
        return head;
    }
};