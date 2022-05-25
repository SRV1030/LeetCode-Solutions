// LIS
// Actually here we are counting the longest increasing sequence as well except there are two dimensions we need to consider. And also we should remember the o(nlogn) solution in LIS, where the essential greedy concept is trying to

// make the all the elements in the collector as small as possible, especially the last one which is the gate to control the size of the collector - the longest length;
// append the bigger ones to the collector;
// But here we need to make some modifications since there are two dimensions to consider. To ensure the two dimensions array can be compressed into one dimension and meantime the requirements of the two conditions above are also properly met, just sorting is not enough here.

// we need to convert this 2-dimentsion problem to a 1-dimension LIS: first sort the array via the width in ascending order and then sort the sub-array with the same width in descending order (the height) then the two conditions in LIS will also be met traversing from the smallest width to the biggest: and the height will be used as that in LIS - the last element will be updated to be as smaller as possible and meantime maintain the envelopes constraint since its width order will always be valid, furthermore the condition 2 is also met just as that in LIS.
// Note if we do not sort the sub-arrays (with the same width) in descending order, the LIS in the height is then invalid. Suppose the sub-arrays are also sorted in ascending order, the height in the same width will be appended in our LIS method, wrong result. To sort the heights in the same width in descending order will avoid this case by updating the height in the same width since we are using lower_bound.

// Time complexity now becomes O(nlogn) taking up O(n) space.

// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& en) {
//        int mx=1,n=en.size();
//        vector<int>dp(n+1);
//         sort(en.begin(),en.end());
//         dp[0]=1;
//        for(int i=1;i<n;i++){
//            dp[i]=1;
//            for(int j=0;j<i;j++)
//                if(en[j][0]<en[i][0] && en[j][1]<en[i][1] && dp[i]<dp[j]+1)dp[i]=dp[j]+1;
//            mx=max(mx,dp[i]);
//        } 
//        return mx; 
//     }
// };

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) { 
       vector<int>dp;
        sort(en.begin(),en.end(),[](vector<int>&a,vector<int>&b){ return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);});
       for(auto &pair:en){ 
           auto itr=lower_bound(dp.begin(),dp.end(),pair[1]);
           if(itr==dp.end()) dp.push_back(pair[1]);
           else if(*itr>pair[1])*itr=pair[1];
       } 
       return dp.size(); 
    }
};