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
    ListNode* rev(ListNode* head){
        if(!head) return head;
        ListNode *cur=head,*prev=NULL,*nxt;
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* h=rev(head);
        stack<int>st;
        vector<int>v;
        while(h){
            while(!st.empty() && h->val>=st.top())st.pop();
            v.push_back(st.empty()?0:st.top());
            st.push(h->val);
            h=h->next;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};