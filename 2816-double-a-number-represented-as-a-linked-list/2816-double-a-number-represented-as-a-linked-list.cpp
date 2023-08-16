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
    ListNode* doubleIt(ListNode* head) {
        ListNode* r=rev(head),*ans=r,*pv;
        int c=0;
        while(r){
            int v=r->val*2+c;
            c=v/10;
            v%=10;
            r->val=v;
            pv=r;
            r=r->next;
        }
        if(c)pv->next=new ListNode(1);
        return rev(ans);
    }
};