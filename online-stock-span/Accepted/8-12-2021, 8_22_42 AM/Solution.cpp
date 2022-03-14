// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<int>st;
    vector<int>v;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        while(!st.empty() && price>=v[st.top()])st.pop();
        int a=st.empty()?i+1:i-st.top();
        st.push(i++);
        return a;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */