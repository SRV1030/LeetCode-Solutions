// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public: stack<int>st;
        vector<int>v;
        int i=0;        
    StockSpanner() {
        
    }
    
    int next(int p) {
        v.push_back(p);
        while(!st.empty() && p>=v[st.top()]) st.pop();
        int r=st.empty()? i+1:i-st.top();
        st.push(i++);
        return r;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */