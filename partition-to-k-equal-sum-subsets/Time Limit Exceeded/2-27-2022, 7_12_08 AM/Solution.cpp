// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
public: bool f=false;
        int n,s=0;
        vector<int>vis;
    void dfs(vector<int>& nums,int ind,int cs,int c,int k){
        if(f || cs<0) return;
        if(c==k){
            f=true;
            return;
        }
        if(cs==0){
            c++;
            dfs(nums,0,s,c,k);
            return;
        }
        for(int i=ind;i<n;i++){
            if(!vis[i]) {
                if(cs>=0){                    
                    vis[i]=1;
                    dfs(nums,i,cs-nums[i],c,k);
                    vis[i]=0;
                }
            }
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        for(auto& i:nums)s+=i;
        if(s%k) return false;
        vis=vector<int>(n,0);
        s/=k;
        dfs(nums,0,s,0,k);
        return f;
    }
};