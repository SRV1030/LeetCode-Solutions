class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        stack<long>st;
        vector<long>ps(nums.size()+1);
        long res=0;
        for(int i=0;i<nums.size();i++)ps[i+1]=nums[i]+ps[i];
        for(int i=0;i<=nums.size();i++){
            while(!st.empty() && (i==nums.size()||nums[st.top()]>nums[i])){
                int j=st.top();
                st.pop();
                res= max(res,nums[j]*(ps[i]-ps[st.empty()?0:st.top()+1]));
            }
            st.push(i);
        }
        return res%1000000007;
    }
};