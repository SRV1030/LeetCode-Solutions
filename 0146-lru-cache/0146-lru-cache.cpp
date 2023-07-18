class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node*prev;
        Node*next;
        Node(int k,int v){
            key=k;
            val=v;
        }
    };
    Node *h=new Node(-1,-1),*t=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>mp;
    void addNode(Node *n){
        Node *temp=h->next;
        h->next=n;
        n->next=temp;
        n->prev=h;
        temp->prev=n;
    }
    void deleteNode(Node *node){
        Node *temp=node->prev;
        temp->next=node->next;
        node->next->prev=temp;
    }
    LRUCache(int capacity) {
        cap=capacity;
        h->next=t;
        t->prev=h;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* res=mp[key];
            mp.erase(key);
            deleteNode(res);
            addNode(res);
            mp[key]=h->next;
            return res->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node *r=mp[key];
            mp.erase(key);
            deleteNode(r);
        }
        else if(mp.size()==cap){
            mp.erase(t->prev->key);
            deleteNode(t->prev);
        }
        addNode(new Node(key,value));
        mp[key]=h->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */