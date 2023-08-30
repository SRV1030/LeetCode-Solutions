class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int>st;
        long ans=0;
        for(int i=1;size(st)<n;++i)
            if(!st.count(target-i)){
                st.insert(i);
                ans+=i;
            }
        return ans;
    }
};