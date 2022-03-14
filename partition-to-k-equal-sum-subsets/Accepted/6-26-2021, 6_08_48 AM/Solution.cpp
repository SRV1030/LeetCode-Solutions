// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
public: bool ans=false;
    int n,s;
    void dfs(vector<int>& nums, int k,int curS,int sum,vector<int> &vis,int ind,int c){
        if(ans || curS<0) return;
        if(c==k){
            ans=true;
            return;
        }
        if(curS==0){
            c++;
            dfs(nums,k,sum,sum,vis,0,c);
        }
        for(int i=ind;i<n;i++){
           if(vis[i]==0){
               if(curS>=0){                   
                 vis[i]=1;
                 dfs(nums,k,curS-nums[i],sum,vis,i,c);
                  vis[i]=0;
               }
               
           }
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size(),s=0;
        for(auto i:nums)s+=i;
        if(s%k) return false;
        vector<int>vis(n,0);
        dfs(nums,k,s/k,s/k,vis,0,0);
        return ans;
    }
};