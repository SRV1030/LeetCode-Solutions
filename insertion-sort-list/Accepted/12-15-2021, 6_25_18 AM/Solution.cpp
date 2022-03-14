// https://leetcode.com/problems/insertion-sort-list

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
    ListNode* sorted;
    void sortedInsert(ListNode* cur){
        if(!sorted || cur->val<sorted->val){
            cur->next=sorted;
            sorted=cur;
        }
        else{
            ListNode * pre=sorted;
            while(pre->next && pre->next->val<cur->val) pre=pre->next;
            cur->next=pre->next;
            pre->next=cur;
        }
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode * cur=head;
        sorted=NULL;
        while(cur){
            ListNode* nxt=cur->next;
            sortedInsert(cur);
            cur=nxt;
        }
        return sorted;
    }
};