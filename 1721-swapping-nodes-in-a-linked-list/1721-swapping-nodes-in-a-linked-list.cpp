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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* f=head,*sh=head,*st;
        k--;
       while(f && k--)f=f->next;
       st=f->next;
       while(st){
           sh=sh->next;
           st=st->next;
       } 
       swap(f->val,sh->val);
        return head;
    }
};