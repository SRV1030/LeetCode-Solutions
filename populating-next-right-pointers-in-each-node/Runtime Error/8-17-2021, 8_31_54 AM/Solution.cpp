// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size()-1;
            for(int i=0;i<n;i++){
                Node *t=q.front();
                q.pop();
                t->next= q.empty()?NULL:q.front();
                if(t->left){
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            Node *t=q.front();
            q.pop();
            t->next=NULL;
            if(t->left){
                q.push(t->left);
                q.push(t->right);                
            }
        }
        return root;
    }
};