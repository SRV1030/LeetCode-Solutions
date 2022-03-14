// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* cur=head,*prev=NULL,*nxt;
        int c=0;
        while(cur){
            if(++c==left){
                ListNode *rtail=prev,*lhead=cur;
                while(c<=right){
                    nxt=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=nxt;
                    c++;
                }
                if(rtail==NULL) head=prev;
                else rtail->next=prev;
                lhead->next=cur;
                return head;                
            }
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};