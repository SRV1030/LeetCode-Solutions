// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
    ListNode* deleteDuplicates(ListNode* head) {
      if(!head) return head;
      ListNode*ans= new ListNode(0,head),*p=ans;
      while(p && p->next){              
            while(p->next && p->next->next && p->next->val==p->next->next->val){
               int v=p->next->val;
                while(p->next && p->next->val==v)p->next=p->next->next;
            }
          
        p=p->next;
      }
      p=ans->next;
        delete ans;
      return p;
    }
};