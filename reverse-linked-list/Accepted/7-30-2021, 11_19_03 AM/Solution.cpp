// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur=head,*prev=NULL,*nxt=NULL;
        while(cur){
            nxt=cur->next;
            cur->next=prev;            
            prev=cur;
            cur=nxt;            
        }
        head=prev;
        return head;
    }
};