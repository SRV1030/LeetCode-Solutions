// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *f=head,*s=head;
        while(f->next){
            s=s->next;
            f=f->next->next;
            if(s==f){
                ListNode *e=head;
                while(s!=e){
                    s=s->next;
                    e=e->next;
                }
                return e;
            }
        }
        return NULL;
    }
};