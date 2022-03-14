// https://leetcode.com/problems/merge-nodes-in-between-zeros

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(0),*h=ans;
        head=head->next;
        int s=0;
        while(head){
            if(!head->val){
                ans->next=new ListNode(s);
                s=0;
                ans=ans->next;
            }
            else s+=head->val;
            head=head->next;
        }
        return h->next;
    }
};