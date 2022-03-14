// https://leetcode.com/problems/add-two-numbers-ii

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
    void Reverse( ListNode **headp){
        ListNode *p=NULL,*c=*headp,*n=NULL;
        while(c){
            n=c->next;   
            c->next=p;
            p=c;  
            c=n;
        }
        *headp=p;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        Reverse(&l1);
        Reverse(&l2);
        ListNode* ans= new ListNode();
        ListNode *head=ans;
        int c=0;
        while(l1 && l2){
            int s=l1->val+l2->val;
            if(s>=9){
                ListNode *temp=new ListNode(s%10+c);
                ans->next=temp;               
                c=1;
            }
            else{
                ListNode *temp=new ListNode(s+c);
                ans->next=temp;
                c=0;
            }
            l1=l1->next;
            l2=l2->next;
            ans=ans->next;
        }
        while(l1){
            int s=l1->val+c;
            if(s>=9){
                ListNode *temp=new ListNode(s%10);
                ans->next=temp;
                c=1;
            }
            else{
                ListNode *temp=new ListNode(s+c);
                ans->next=temp;
                c=0;
            }
            l1=l1->next;
             ans=ans->next;
        }
        while(l2){
            int s=l2->val+c;
            if(s>=9){
                ListNode *temp=new ListNode(s%10);
                ans->next=temp;
                c=1;
            }
            else{
                ListNode *temp=new ListNode(s+c);
                ans->next=temp;
                c=0;
            }
            l2=l2->next;
             ans=ans->next;
        }
        if(c){
            ListNode *temp=new ListNode(1);
                ans->next=temp;
            ans=ans->next;
        }
        head=head->next;
        Reverse(&head);
        return head;
    }
};