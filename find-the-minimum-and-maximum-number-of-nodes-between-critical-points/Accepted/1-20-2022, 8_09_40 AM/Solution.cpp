// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next)return {-1,-1};
        ListNode* prv=head,*cur=prv->next,*nxt=cur->next;
        int f=-1,pcp=-1,ncp=-1,ind=1,mnd=INT_MAX,mxd=INT_MIN;
        while(nxt){
            if((prv->val>cur->val && cur->val<nxt->val) || (prv->val<cur->val && cur->val>nxt->val)){
                if(pcp==-1){
                  pcp=ind; 
                    f=ind;
                }  
                else{
                    ncp=ind;
                    mnd=min(mnd,ncp-pcp);
                    mxd=ncp-f;
                    pcp=ncp;
                }
            }
            ind++;
            prv=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        if(mxd==INT_MIN) return {-1,-1};
        return {mnd,mxd};
    }
};