// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    // int length(ListNode* head){
    //     ListNode* t=head;
    //     int c=0;
    //     while(t!=nullptr){
    //         t=t->next;
    //         c++;
    //     }
    //     return c;
    // }
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if(!head) return head;
    //     int l= length(head);
    //     int c=l-n;
    //     if(c==0){
    //         head=head->next;
    //         return head;
    //     } 
    //     ListNode* t=head;
    //     while(c>1 && t!=nullptr && t->next!=nullptr){
    //         t=t->next;
    //         c--;
    //     } 
    //     t->next=t->next->next!=nullptr?t->next->next:nullptr;
    //     return head;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*s=dummy,*f=dummy;
        for(int i=0;i<n+1;i++)f=f->next;
        while(f){
            s=s->next;
            f=f->next;
        } 
        s->next=s->next->next!=nullptr?s->next->next:nullptr;
        return head;
    }
};