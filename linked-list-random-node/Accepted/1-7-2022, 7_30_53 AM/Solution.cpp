// https://leetcode.com/problems/linked-list-random-node

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;
    int c=0;
    Solution(ListNode* head) {
        this->head=head;
        ListNode *t=head;
        while(t){
            c++;
            t=t->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int x=rand()%c;
        ListNode *t=head;
        while(x--) t=t->next;
        return t->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */