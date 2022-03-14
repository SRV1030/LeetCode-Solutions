// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *sh=new ListNode(0,head),*lh=new ListNode(0,head),*s=sh,*l=lh,*cur=head;
        while(cur){
            if(cur->val>=x){
                l->next=new ListNode(cur->val);
                l=l->next;
            }
            else{
                s->next=new ListNode(cur->val);
                s=s->next;
            }
            cur=cur->next;
        }
        if(!sh->next)return lh->next;
        lh=lh->next;
        s->next=lh;
        return sh->next;
    }
};