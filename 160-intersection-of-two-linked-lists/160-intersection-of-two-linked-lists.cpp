/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     int getCount(ListNode *head){
//         int c=0;
//         ListNode *h=head;
//         while(h){
//             c++;
//             h= h->next;
//         }
//         return c;
//     }
//     ListNode *getInter(ListNode *headA, ListNode *headB,int c){
//         while(c--) headA=headA->next;
//         while(headA && headB){
//             if(headA==headB) return headA;
//             headA=headA->next;
//             headB=headB->next;
//         }
//         return NULL;
//     }
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int c1=getCount(headA);
//         int c2=getCount(headB);
//         int c=abs(c1-c2);
//         if(c1>c2) return getInter(headA,headB,c);
//         else return getInter(headB,headA,c);        
//     }
// };


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA,*b=headB;
        while(a!=b){
            a=a?a->next:headB;
            b=b?b->next:headA;
        }
        return a;
    }
};