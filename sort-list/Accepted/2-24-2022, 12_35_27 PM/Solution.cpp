// https://leetcode.com/problems/sort-list

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
    ListNode* sortedMerge(ListNode *a,ListNode *b){
        if(!a) return b;
        if(!b) return a;
        ListNode* c=NULL;
        if(a->val<=b->val){
            c=new ListNode(a->val);
            c->next=sortedMerge(a->next,b);
        }
        else{
            c=new ListNode(b->val);
            c->next=sortedMerge(a,b->next);
        }
        return c;
    }
    void divMid(ListNode *head,ListNode **a,ListNode **b){
        if(!head || !head->next) return;
        ListNode *s=head,*f=head->next;
        while(f){
            f=f->next;
            if(f){
                s=s->next;
                f=f->next;
            }
        }
        *a=head;
        *b=s->next;
        s->next=NULL;
        return;        
    }
    ListNode* sortList(ListNode* head) {
         if(!head || !head->next) return head;
         ListNode *a=NULL,*b=NULL;
        divMid(head,&a,&b);
        a=sortList(a);
        b=sortList(b);
        head=sortedMerge(a,b);
        return head;
    }
};