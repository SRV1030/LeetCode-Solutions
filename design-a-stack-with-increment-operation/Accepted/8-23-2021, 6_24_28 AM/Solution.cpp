// https://leetcode.com/problems/design-a-stack-with-increment-operation

class CustomStack {
public:
    vector<int>v;
    int s;
    CustomStack(int maxSize) {
        s=maxSize;
    }
    
    void push(int x) {
        if(v.size()==s) return;
        v.push_back(x);
    }
    
    int pop() {
        if(v.empty()) return -1;;
        int x=v.back();
        v.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        k=k>v.size()?v.size():k;
        for(int i=0;i<k;i++)v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */