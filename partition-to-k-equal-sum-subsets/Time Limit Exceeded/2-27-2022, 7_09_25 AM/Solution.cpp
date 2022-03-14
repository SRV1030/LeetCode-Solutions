// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
public:
    bool f=false;
    vector<int>vis;
    int s=0;
    void dfs(vector<int>& nums, int cs,int k,int ind,int c){
        if(f || cs<0) return;
        if(c==k){
            f=true;
            return;
        }
        if(cs==0){
            c++;
            dfs(nums,s,k,0,c); 
        }
        for (int i=ind;i<nums.size();i++){
            if(!vis[i]){
                if(cs>=0){                    
                    vis[i]=1;
                    dfs(nums,cs-nums[i],k,i,c);
                    vis[i]=0;
                }
            }
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) { 
        for(auto&i:nums)s+=i;
        if(s%k) return false;
        s/=k;
        vis=vector<int>(nums.size());
        dfs(nums,s,k,0,0);
        return f;
    }
};