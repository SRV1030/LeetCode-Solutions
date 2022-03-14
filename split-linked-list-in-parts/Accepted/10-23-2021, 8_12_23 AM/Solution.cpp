// https://leetcode.com/problems/split-linked-list-in-parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur=head;
        int c=0;
        while(cur){
            cur=cur->next;
            c++;
        }
        vector<ListNode*> ans(k);
        int i=0;
        cur=head;
        while(c>0){
            int w=ceil((float)c/(float)k);
            c-=w;
            k--;
            ListNode*root=cur;
            while(w--!=1) root=root->next;
            ans[i++]=cur;
            cur=root->next;
            root->next=NULL;
        }
        return ans;
    }
};