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
    ListNode* merge(ListNode *a,ListNode *b){
        if(!a) return b;
        if(!b) return a;
        if(a==b) return a;
        ListNode *res=NULL;
        if(a->val<=b->val){
            res=a;
            res->next=merge(a->next,b);
        }
        else{
            res=b;
            res->next=merge(a,b->next);
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        vector<ListNode*> v;
        int i=0,j=n-1;
        while(i<=j){
            ListNode *x=merge(lists[i],lists[j]);
            v.push_back(x);
            i++;
            j--;
        }
        return mergeKLists(v);
    }
};