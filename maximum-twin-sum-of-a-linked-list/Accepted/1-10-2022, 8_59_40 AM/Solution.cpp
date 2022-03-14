// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    ListNode* rev(ListNode *head){
        ListNode*cur=head,*prev=NULL,*nxt=NULL;
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode*f=head->next,*s=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode *pm=head,*sec=s->next;
        s->next=NULL;
        sec=rev(sec);
        int mx=0;
        while(pm && sec){
            int x=pm->val+sec->val;
            if(x>mx)mx=x;
            pm=pm->next;
            sec=sec->next;
        }
        return mx;        
    }
};