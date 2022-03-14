// https://leetcode.com/problems/palindrome-linked-list

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
    ListNode *rev(ListNode *head){
        if(!head) return NULL;
        ListNode *prev=NULL,*nxt=NULL;
        while(head){
            nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* s=head,*f=head;
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* cur=head;
        s->next=rev(s->next);
        s=s->next;
        while(s){
            if(cur->val!=s->val) return false;
            cur=cur->next;
            s=s->next;
        }
        return true;
    }
};