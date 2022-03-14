// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* o=new ListNode(head->val),*oh=o,*e=new ListNode(head->next->val),*eh=e;
        head=head->next->next;
        while(head){
            o->next=new ListNode(head->val);
            head=head->next;
            o=o->next;
            if(head){
                e->next=new ListNode(head->val);
                head=head->next;
                e=e->next;
            }
        }
        o->next=eh;
        return oh;
    }
};