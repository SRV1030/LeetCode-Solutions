// https://leetcode.com/problems/rotate-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        ListNode*p=head;
        int c=1;
        while(p->next && ++c) p=p->next;
        k=k%c;
        k=c-k;
        p->next=head;
        while(k--)p=p->next;
        head=p->next;
        p->next=NULL;        
        return head;
    }
};