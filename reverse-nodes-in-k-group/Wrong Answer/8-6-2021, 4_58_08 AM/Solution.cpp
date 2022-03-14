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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head,*nxt=NULL,*prv=NULL; 
        int c=0;
        while(cur && c<k){
            nxt=cur->next;
            cur->next=prv;
            prv=cur;
            cur=nxt;     
            c++;
        }
        if(nxt)head->next=reverseKGroup(nxt,k);
        return prv;
    }
};