// https://leetcode.com/problems/design-hashmap

class MyHashMap {
    
private: int mx=1001;
public:
    /** Initialize your data structure here. */
    struct Node{
        int key;
        int val;
        Node* next, *prev;
        Node(int k,int v){
            key=k;
            val=v;
            next=prev=NULL;
        }
    };
    Node *mp[1001];
    MyHashMap() {
        for (int i=0;i<mx;++i)
            mp[i] = NULL;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int k=key%mx;
        Node*cur=mp[k];
        if(!cur) mp[k]=new Node(key,value);
        else{
            Node*prev=NULL;
            while(cur!=NULL){
                if(cur->key==key){
                    cur->val=value;
                    return;
                }
                prev=cur;
                cur=cur->next;                
            }
            cur=new Node(key,value); 
            cur->next=NULL;
            cur->prev=prev;
            prev->next=cur;
        }
        
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int k=key%mx;
        Node*cur=mp[k];
        if(!cur) return -1;
        else{
            while(cur!=NULL){
                if(cur->key==key) return cur->val;
                cur=cur->next;                
            }
            return -1;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k=key%mx;
        Node*cur=mp[k];
        while(cur!=NULL){
            if(cur->key==key){
                if(!cur->prev && !cur->next){
                    delete cur;
                    mp[k]=NULL;
                    return;
                } 
                else if (!cur->prev){
                    mp[k]=cur->next;
                    mp[k]->prev=NULL;
                }
                else if (!cur->next) cur->prev->next=NULL;
                else{
                    cur->prev->next=cur->next;
                    cur->next->prev=cur->prev;
                }
                delete cur;
                return;
            }
            cur=cur->next;                
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