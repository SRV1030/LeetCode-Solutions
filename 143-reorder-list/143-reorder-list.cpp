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
public:int c=0;
    ListNode* rev(ListNode* head){
        if(!head) return head;
        ListNode* cur=head,*prev=NULL,*nxt;
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            c++;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *cur=head,*bh=NULL,*half=head;
        while(cur){
            bh=half;
            half=half->next;
            cur=cur->next;
            if(cur)cur=cur->next;
        }
        bh->next=NULL;
        half=rev(half);
        cur=head;
        while(half){
            ListNode* t=cur;
            cur=cur->next;
            t->next=half;      
            half=half->next;            
            t=t->next; 
            t->next=cur;
        }
    }
};