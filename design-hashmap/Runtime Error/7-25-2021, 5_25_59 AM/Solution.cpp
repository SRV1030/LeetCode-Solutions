// https://leetcode.com/problems/design-hashmap

class MyHashMap {
public:
    /** Initialize your data structure here. */
    struct Node{
        int key;
        int val;
        Node *next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            next=NULL;
        }
    };
    Node *root;
    MyHashMap() {
        root=NULL;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {        
        if(!root){
            root= new Node(key,value);
            return;
        }
        Node *c=root;
        while(c->next){
            if(c->key==key){
                c->val=value;
                return;                
            }
            c=c->next;
        }
        if(c->key==key){
                c->val=value;
                return;                
            }
        Node *t=new Node(key,value);
        c->next=t;        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        Node *c=root;
        while(c){
            if(c->key==key) return c->val;
            c=c->next;
        }        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        Node *c=root;
        Node *p=NULL;
        if(!root) return;
        if(root->key==key)root=root->next;
        while(c){
            if(c->key==key){
                p->next=c->next;
                return;
            }
            p=c;
            c=c->next;
            
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */