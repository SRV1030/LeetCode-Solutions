// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *cur=head;
        while(cur){
            Node *cpy=new Node(cur->val);
            cpy->next=cur->next;
            cur->next=cpy;
            cur=cur->next->next;
        }
        cur=head;
        while(cur){
            cur->next->random=cur->random?cur->random->next:NULL;
            cur=cur->next->next;
        }
        cur=head;
        Node *cpy=head->next,*ans=cpy;
        while(cur){
            cur->next=cur->next->next;
            cpy->next=cpy->next?cpy->next->next:NULL;
            cur=cur->next;
            cpy=cpy->next;
        }
        return ans;
    }
};