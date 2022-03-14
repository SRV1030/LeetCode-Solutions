// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx=0;
        set<int>st(nums.begin(),nums.end());
        for(auto& i:nums){
            if(st.count(i-1)) continue;
            int c=1,cv=i;
            while(st.count(cv+1)){
                c++;
                cv++;
            }
            if(c>mx)mx=c;
        }
        return mx;
    }
};