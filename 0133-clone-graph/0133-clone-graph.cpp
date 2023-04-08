/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public: 
    vector<Node*>vis;
    void dfs(Node *copy,Node *org){
        vis[copy->val]=copy;
        for(auto i:org->neighbors){
            if(!vis[i->val]){
                Node *cpy=new Node(i->val);
                (copy->neighbors).push_back(cpy);
                dfs(cpy,i);
            }else (copy->neighbors).push_back(vis[i->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        vis=vector<Node*>(101,NULL);
        Node *copy=new Node(node->val);
        dfs(copy,node);
        return copy;
    }
};