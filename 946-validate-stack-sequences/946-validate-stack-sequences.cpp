class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int po=0,n=popped.size();
        for(auto& i:pushed){
            while(!st.empty() && st.top()==popped[po]){
                st.pop();
                po++;
            }
            st.push(i);
        }
        while(!st.empty() && po<n && st.top()==popped[po]){
                st.pop();
                po++;
        }
        return st.empty();
    }
};