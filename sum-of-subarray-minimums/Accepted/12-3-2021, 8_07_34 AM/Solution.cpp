// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    long long MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        vector<int>l(arr.size(),-1),r(arr.size(),arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()])st.pop();
            if(st.empty()) l[i]=i+1;
            else l[i]=i-st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()])st.pop();
            if(st.empty()) r[i]=arr.size()-i;
            else r[i]=st.top()-i;
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<arr.size(); i++){
            long long prod = (l[i]*r[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }        
        return res%MOD;
    }
};