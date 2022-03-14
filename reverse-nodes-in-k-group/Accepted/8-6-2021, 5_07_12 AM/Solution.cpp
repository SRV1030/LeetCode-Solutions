// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    int count(ListNode* head){
        ListNode* p=head;
        int c=0;
        while(p){
            c++;
            p=p->next;
        }
        return c;
    }
    ListNode* reverse(ListNode* head, int k,int rem){
        if(rem<k) return head;
        ListNode* cur=head,*nxt=NULL,*prv=NULL; 
        int c=0;
        while(cur && c<k){
            nxt=cur->next;
            cur->next=prv;
            prv=cur;
            cur=nxt;     
            c++;
        }
        if(nxt)head->next=reverse(nxt,k,rem-k);
        return prv;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k,count(head));
    }
};