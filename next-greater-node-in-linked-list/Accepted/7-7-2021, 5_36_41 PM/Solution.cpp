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
        ListNode* c=head,*p=NULL,*n=NULL;
        while(c){
            n=c->next;            
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head= rev(head);
        stack<int>st;
        vector<int>v;
        while(head){
            while(!st.empty() && head->val>=st.top())st.pop();
            int a=st.empty()?0:st.top();
            st.push(head->val);
            head=head->next;
            v.push_back(a);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};