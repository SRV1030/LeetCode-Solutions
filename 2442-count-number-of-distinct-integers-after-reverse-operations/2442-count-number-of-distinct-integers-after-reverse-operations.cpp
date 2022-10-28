class Solution {
public:
    int rev(int i){
        int ans=0;
        while(i){
            ans=ans*10+i%10;
            i/=10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>st(begin(nums),end(nums));
        for(auto&i:nums)st.insert(rev(i));
        return size(st);
    }
};