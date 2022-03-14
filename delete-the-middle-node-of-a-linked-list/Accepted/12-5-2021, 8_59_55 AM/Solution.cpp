// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;
        if(!head->next){
            delete head;
            return NULL;
        }
        ListNode* s=head,*f=head,*pr;
        while(f && f->next){
            pr=s;
            s=s->next;
            f=f->next->next;
        }
        pr->next=s->next;
        delete s;
        return head;
    }
};