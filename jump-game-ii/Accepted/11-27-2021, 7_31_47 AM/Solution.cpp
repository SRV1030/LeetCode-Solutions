// https://leetcode.com/problems/jump-game-ii

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         vector<int> pos(nums.size()),mis(nums.size(),INT_MAX-1);
//         mis[0]=0;
//         for(int i=1;i<nums.size();i++)
//             for(int j=0;j<i;j++){
//                 if(nums[j]+j>=i){
//                     if(mis[j]+1<mis[i]){
//                         pos[i]=j;
//                         mis[i]=1+mis[j];
//                     }
//                 }
//             }
//         return mis[nums.size()-1];
//     }
// };

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>mis(n,INT_MAX-1);
//         mis[0]=0;
//         for(int i=1;i<n;i++)
//             for(int j=0;j<i;j++){
//                 if(nums[j]+j>=i){
//                     if(mis[j]+1<mis[i])
//                         mis[i]=1+mis[j];
//                 }
//             }
//         return mis[n-1];
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),cmx=0,mxj=0,ans=0;
        for(int i=0;i<n-1;i++){
            mxj=max(mxj,i+nums[i]);
            if(i==cmx){
                ans++;
                cmx=mxj;               
            }
        }
        return ans;
    }
};