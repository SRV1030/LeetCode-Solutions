class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double>st;
        sort(begin(nums),end(nums));
        int c=0;
        for(int i=0,j=size(nums)-1;i<=j;i++,j--){
            double avg=(nums[i]+nums[j])/2.0;
            if(st.insert(avg).second)++c;
        }
        return c;
    }
};