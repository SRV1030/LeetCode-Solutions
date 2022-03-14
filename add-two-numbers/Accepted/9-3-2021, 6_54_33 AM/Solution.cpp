// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* add=new ListNode(),*head=add;
        int c=0;
        while(l1 && l2){
            int s=l1->val+l2->val+c;
            if(s>9){
                add->next=new ListNode(s%10);
                c=1;
            }else{
                add->next=new ListNode(s);
                c=0;
            }
            l1=l1->next;
            l2=l2->next;
            add=add->next;
        }
        while(l1){
            int s=l1->val+c;
            if(s>9){
                add->next=new ListNode(s%10);
                c=1;
            }else{
                add->next=new ListNode(s);
                c=0;
            }
            l1=l1->next;
            add=add->next;
        }
        while(l2){
            int s=l2->val+c;
            if(s>9){
                add->next=new ListNode(s%10);
                c=1;
            }else{
                add->next=new ListNode(s);
                c=0;
            }
            l2=l2->next;
            add=add->next;
        }
        if(c){
            add->next=new ListNode(1);
            add=add->next;
        }
        return head->next;
    }
};