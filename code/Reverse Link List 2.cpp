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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (m==n)   return head;
        ListNode *p = head,*q;
        ListNode *s,*t,*w;
        int cnt = 0;
        while(cnt < m-2)
            {p = p->next;cnt ++;}
        if (m == 1) s = head;
        else s = p->next;
        t = s->next;
        
        for (int i=0;i<n-m;++i)
        {
            w = t->next;
            t->next = s;
            s = t;
            t = w;
        }
        if (m == 1)
        {
            w = head;
            head = s;
            w->next = t;
        }
        else
        {
            w = p->next;
            p->next = s;
            w->next = t;
        }
        return head;
    }
};