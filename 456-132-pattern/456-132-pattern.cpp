class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return false;
        stack<int> st;
        vector<int>sl(n);
        sl[0]=nums[0];
        for(int i=1;i<n;i++)sl[i]=min(sl[i-1],nums[i]);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=sl[i]) st.pop();
            if(!st.empty() && st.top()<nums[i]) return true;
            st.push(nums[i]);
        }
        return false;
        
    }
};