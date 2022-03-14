// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int t[n],mx=1;
        t[0]=1;
        for(int i=1;i<n;i++){
            t[i]=1;
            for(int j=0;j<i;j++)
                if(nums[i]%nums[j]==0 && t[i]<1+t[j]){
                    t[i]=1+t[j];
                    mx=max(mx,t[i]);
                }
        }
        vector<int> v;
        int i,prv=-1;
        for(i=n-1;i>=0;i--){
            if(t[i]==mx && (prv==-1 || prv%nums[i]==0)){
                v.push_back(nums[i]);
                prv=nums[i];
                mx--;
            }  
        }
        return v;
    }
};