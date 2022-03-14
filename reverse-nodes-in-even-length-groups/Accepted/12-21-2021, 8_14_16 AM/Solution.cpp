// https://leetcode.com/problems/reverse-nodes-in-even-length-groups

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
    ListNode * rev(ListNode *head,int mxl){
        if(!head) return head;
        ListNode* t=head;
        int c=1;
        for(;c<mxl && t->next;t=t->next,c++);
        if(c%2){
            t->next=rev(t->next,mxl+1);
            return head;
        }
        ListNode* prev,*nxt=NULL;
        prev=t->next;
        t=head;
        for(int i=0;i<c && head;i++){
           nxt=head->next;
           head->next=prev;
           prev=head;
           head=nxt;
        }
        t->next=rev(t->next,mxl+1);
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return rev(head,1);
    }
};