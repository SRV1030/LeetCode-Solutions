// https://leetcode.com/problems/min-stack

class MinStack {
public: long long int mn;
    stack<long long int>st;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(long long int val) {
        if(st.empty()){
            mn=val;
            st.push(val);
            return;
        }
        if(val>=mn)st.push(val);
        else{
            st.push(2*val-mn);
            mn=val;
        }
    }
    
    void pop() {
        if(st.empty())return;
        if(st.top()>mn)st.pop();
        else{
            mn=2*mn-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top()>mn) return st.top();
        return mn;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */