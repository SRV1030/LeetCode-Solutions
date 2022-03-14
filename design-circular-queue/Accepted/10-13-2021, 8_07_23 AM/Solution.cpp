// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public: int c,f,r,cap,*q;
    MyCircularQueue(int k) {
        c=0;
        cap=k;
        f=0;r=-1;
        q=new int[k];
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        c++;
        r=(r+1)%cap;
        q[r]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        f=(f+1)%cap;
        c--;
        return true;
    }
    
    int Front() {
       if(isEmpty()) return -1;
       return q[f];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        return c==0;
    }
    
    bool isFull() {
        return c==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */