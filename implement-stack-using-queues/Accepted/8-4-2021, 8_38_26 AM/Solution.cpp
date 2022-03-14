// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
public:queue<int>q1,q2;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!q1.empty()){
            int e=q1.front();
            q2.push(e);
            q1.pop();
        }
        q1.push(x);
         while(!q2.empty()){
            int e=q2.front();
            q1.push(e);
            q2.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty())return -1;
        int e=q1.front();
        q1.pop();
        return e;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */