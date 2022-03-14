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
    int Count(ListNode* head){
        ListNode*p=head;
        int c=0;
        while(p){
            p=p->next;
            c++;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n=Count(head);
        k=k%n;
        if(!k)return head;
        k=n-k-1;
        ListNode*p=head,*h=head;
        while(k--) p=p->next;
        ListNode* q=p->next;
        p->next=NULL;
        head=q;
        while(q->next) q=q->next;
        q->next=h;
        return head;
    }
};