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
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head==NULL || head->next==NULL)   return head;
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* q = head, *t = p;
        while(q!=NULL && q->next!=NULL)
        {
            ListNode *tmp1 = q->next;
            ListNode *tmp2 = q->next->next;
            t->next = tmp1;
            tmp1->next = q;
            q->next = tmp2;
            
            t = q;
            q = tmp2;
        }
        q = p->next;
        delete p;
        return q;
    }
};