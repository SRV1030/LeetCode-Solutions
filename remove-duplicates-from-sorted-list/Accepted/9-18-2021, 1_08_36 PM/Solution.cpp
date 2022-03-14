// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* h=new ListNode(head->val),*ans=h,*cur=head->next;
        while(cur){
            if(h->val!=cur->val){
                h->next=new ListNode(cur->val);
                h=h->next;
            }
            cur=cur->next;
        }
        return ans;
    }
};