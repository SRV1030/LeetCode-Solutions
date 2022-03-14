// https://leetcode.com/problems/design-linked-list

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct node{
        int val;
        node *next;
        node(){
            val=0;
            next=NULL;
        }
        node(int x){
            val=x;
            next=NULL;
        }
    };
    node *ll;
    int c;
    
    MyLinkedList() {
        ll=NULL;
        c=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=c) return -1;
        node *p=ll;
        if(index==0) return p->val;
        for(int i=0;i<index;i++) {
            p=p->next;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* t=new node(val);
        if(!ll)ll=t;
        else {
            t->next=ll;
            ll=t;
        } 
        c++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
         node* t=new node(val);
        if(!ll)ll=t;
        else{
            node *p=ll;           
            while(p->next) p=p->next;            
            p->next=t;
        }
        c++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>=c) return;
        node* t=new node(val);
        if(index==0){
            t->next=ll;
            ll=t;
        }
        else{            
            node *pre=NULL,*cur=ll;  
            for(int i=0;i<index;i++){
                pre=cur;
                cur=cur->next;
            }
            pre->next=t;
            t->next=cur;
        }        
        c++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=c) return;
         node *p=ll;  
        if(index==0){
            ll=ll->next;
            delete p;
        }
        else{
          node *pre=NULL;  
            for(int i=0;i<index;i++)  {
            pre=p;
            p=p->next;
        }
        if(pre && p)
            pre->next=p->next;
        }
        c--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */