// https://leetcode.com/problems/next-greater-node-in-linked-list

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
    ListNode* rev(ListNode* head) {
        ListNode* prev=NULL,*nxt=NULL;
        while(head){
           nxt=head->next;
           head->next=prev;
           prev=head;
           head=nxt;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* r=rev(head);
        stack<int>st;
        vector<int>v;
        while(r){
            while(!st.empty() && r->val>=st.top())st.pop();
            v.push_back(st.empty()?0:st.top());
            st.push(r->val);
            r=r->next;            
        }
        reverse(v.begin(),v.end());
        return v;
    }
};