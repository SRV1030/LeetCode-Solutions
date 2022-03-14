// https://leetcode.com/problems/merge-in-between-linked-lists

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* c1=list1, *e1=list1,*c2=list2;
        b-=(a-2);
        a-=1;
        while(c1 && a--){
            c1=c1->next;
        } 
        if(!c1) return list2;
        e1=c1;
        while(e1 && b--){
            e1=e1->next;
        }
        c1->next=list2;
        while(c2->next)c2=c2->next;
        c2->next=e1;
        return list1;
    }
};