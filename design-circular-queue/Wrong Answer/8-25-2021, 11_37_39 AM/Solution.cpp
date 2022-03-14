// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public: int s,f,r,*q;
    MyCircularQueue(int k) {
        s=k-1;
        f=r=-1;
        q=new int[k];
    }
    
    bool enQueue(int value) {
        if((f==0 && r==s)|| (r==((f-1)%s))) return false;
        if(f==-1){
            f=r=0;
            q[r]=value;
        }
        else{
            r=(r+1)%(s+1);
            q[r]=value;
        }
        return true;
    }
    
    bool deQueue() {
        if(f==-1) return false;
        q[f]=-1;
        if(f==r)f=r=-1;
        else f=(f+1)%(s+1);
        return true;
    }
    
    int Front() {
       if(f==-1) return false;
        return q[f];
    }
    
    int Rear() {
        if(r==-1) return false;
        return q[r];
    }
    
    bool isEmpty() {
        return r==-1;
    }
    
    bool isFull() {
        return (f==0 && r==s)|| (r==(f%s));
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