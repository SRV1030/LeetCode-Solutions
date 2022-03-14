// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode *prv=NULL,*nxt=NULL,*cur=head;
        int k=2;
        while(cur && k--){
            nxt=cur->next;
            cur->next=prv;
            prv=cur;
            cur=nxt;
        }
        if(nxt)head->next=swapPairs(nxt);
        return prv;
    }
};